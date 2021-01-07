# Recipe created by recipetool
# This is the basis of a recipe and may need further editing in order to be fully functional.
# (Feel free to remove these comments when editing.)

# Unable to find any files that looked like license statements. Check the accompanying
# documentation and source headers and set LICENSE and LIC_FILES_CHKSUM accordingly.
#
# NOTE: LICENSE is being set to "CLOSED" to allow you to at least start building - if
# this is not accurate with respect to the licensing of the software being built (it
# will not be in most cases) you must specify the correct value before using this
# recipe for anything other than initial testing/development!
LICENSE = "CLOSED"
LIC_FILES_CHKSUM = ""

SRC_URI = "git://github.com/hubshuffle/python-flask-hello-world.git;protocol=https \
file://python-flask-hello-world.service \
file://0001-change-port.patch \
"

# Modify these as desired
PV = "1.00+git${SRCPV}"
SRCREV = "ef935ecdf7b081fbc86ae9a71812e64a6a138301"

S = "${WORKDIR}/git"
RDEPENDS_${PN} = "python3 python3-flask"
inherit systemd

do_install() {	
	# Specify install commands here	
	install -d "${D}${bindir}"
	install -m 0755 app.py "${D}${bindir}/python-flask-hello-world.py"

	#install service file
	install -d "${D}${systemd_unitdir}/system"
	install -m 0644 "${WORKDIR}/python-flask-hello-world.service" "${D}${systemd_unitdir}/system"
}

FILES_${PN} +="${bindir}/python-flask-hello-world.py ${systemd_unitdir}/system/python-flask-hello-world.service"
SYSTEMD_SERVICE_${PN} = "python-flask-hello-world.service"