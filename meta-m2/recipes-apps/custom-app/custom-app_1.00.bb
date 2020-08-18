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
#inherit systemd 
LICENSE = "CLOSED"
LIC_FILES_CHKSUM = ""

# No information for SRC_URI yet (only an external source tree was specified)
SRC_URI = "file://emb_znsd"
#SRC_URI = "file://emb_znsd.service"

S = "${WORKDIR}"

do_install(){
    install -d ${D}${bindir}
    install -m 0755 emb_znsd "${D}${bindir}/emb_znsd"

    #Install service file
#    install -d "${D}${systemd_system_unitdir}"
#    install -m 0644 ${WORKDIR}/emb_znsd.service \
#    "${D}${systemd_system_unitdir}"
}

FILES_${PN} += "\
${bindir}/emb_znsd \
"
#${systemd_system_unitdir}/emb_znsd.service 
SYSTEM_SERVCIVE_${PN} = "emb_znsd.service"
# NOTE: no Makefile found, unable to determine what needs to be done

