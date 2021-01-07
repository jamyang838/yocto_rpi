FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI = "file://serial-getty@.service"

do_install() {
	if [ ! -z "${SERIAL_CONSOLES}" ] ; then
		default_baudrate=`echo "${SERIAL_CONSOLES}" | sed 's/\;.*//'`
		install -d ${D}${systemd_unitdir}/system/
		install -d ${D}${sysconfdir}/systemd/system/getty.target.wants/
		install -m 0644 ${WORKDIR}/serial-getty1@.service ${D}${systemd_unitdir}/system/
		sed -i -e s/\@BAUDRATE\@/$default_baudrate/g ${D}${systemd_unitdir}/system/serial-getty1@.service

		tmp="${SERIAL_CONSOLES}"
		for entry in $tmp ; do
			baudrate=`echo $entry | sed 's/\;.*//'`
			ttydev=`echo $entry | sed -e 's/^[0-9]*\;//' -e 's/\;.*//'`
			if [ "$baudrate" = "$default_baudrate" ] ; then
				# enable the service
				ln -sf ${systemd_unitdir}/system/serial-getty1@.service \
					${D}${sysconfdir}/systemd/system/getty.target.wants/serial-getty@$ttydev.service
			else
				# install custom service file for the non-default baudrate
				install -m 0644 ${WORKDIR}/serial-getty1@.service ${D}${systemd_unitdir}/system/serial-getty$baudrate@.service
				sed -i -e s/\@BAUDRATE\@/$baudrate/g ${D}${systemd_unitdir}/system/serial-getty$baudrate@.service
				# enable the service
				ln -sf ${systemd_unitdir}/system/serial-getty$baudrate@.service \
					${D}${sysconfdir}/systemd/system/getty.target.wants/serial-getty$baudrate@$ttydev.service
			fi
		done
	fi
}
