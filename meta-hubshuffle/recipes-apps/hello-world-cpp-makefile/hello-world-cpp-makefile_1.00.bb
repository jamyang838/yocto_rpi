LICENSE = "MIT"
LIC_FILES_CHKSUM = " \
file://MIT;md5=0835ade698e0bcf8506ecda2f7b4f302 \
"

SRC_URI = "\
file:///home/yang/yocto/poky/meta-hubshuffle/recipes-apps/hello-world-cpp-makefile/files/hellow-world-cpp-makefile.tar.gz \
"

S = "${WORKDIR}"

do_configure(){
    :
}

do_compile(){
    oe_runmake
}

do_install(){
    oe_runmake install 'DESTDIR=${D}'
}