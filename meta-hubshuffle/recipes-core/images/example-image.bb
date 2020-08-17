require recipes-core/images/core-image-base.bb

#Only allow for machines which start "rpi"
#COMPATIBLE_MACHINE = "^rpi$"

#Be able to generate QT5 sdk
inherit populate_sdk_qt5
IMAGE_INSTALL += "rsync"
RM_OLD_IMAGE = "1"
IMAGE_FEATURES_remove += "splash"
do_rootfs_append(){
    bb.warn("image build 900772!")
}

IMAGE_FEATURES += "ssh-server-dropbear"
IMAGE_INSTALL += "linux-firmware linux-firmware-bcm43430"
IMAGE_INSTALL += "kernel-modules"
IMAGE_INSTALL += "qtquickcontrols2"
IMAGE_INSTALL += "qtvirtualkeyboard"

#IMAGE_INSTALL += "qtquickcontrols"
IMAGE_INSTALL += "wiringpi"

#IMAGE_FSTYPES += "tar.xz ext3 rpi-sdimg"
#add package managment
#EXTRA_IMAGE_FEATURES += "package-management"
#PACKAGE_CLASSES_append = " package_ipk"
#IMAGE_INSTALL_append = "opkg"
#PRSERV_HOST = "localhost:0"
#PACKAGE_CLASS = "package_rpm"


#INSTALL i2c-tools
#IMAGE_INSTALL += "i2c-tools"
#INSTALL vim
#IMAGE_INSTALL += "vim"

#INSTALL network
IMAGE_INSTALL += "networkmanager \
 networkmanager-nmtui \
 networkmanager-bash-completion \
 "
#INSTALL 
IMAGE_INSTALL += "curl"

#
#install app 
#IMAGE_INSTALL += "hello-world-cpp-sources"
#IMAGE_INSTALL += "hello-world-cpp-makefile"
#IMAGE_INSTALL += "python-flask-hello-world"
#IMAGE_INSTALL += "custom-app"
IMAGE_INSTALL_append += "custom-app"
#IMAGE_INSTALL += "cinematicexperience"
