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
inherit systemd 
LICENSE = "CLOSED"
LIC_FILES_CHKSUM = ""

SRC_URI = "file://start_up.sh \
"

S = "${WORKDIR}"

# NOTE: no Makefile found, unable to determine what needs to be done

do_install_append() {
    install -d "${D}${sysconfdir}/profile.d"
    install -m 0644 "${WORKDIR}/start_up.sh" "${D}${sysconfdir}/profile.d"
}
