require recipes-core/images/core-image-base.bb

#Only allow for machines which start "rpi"
#COMPATIBLE_MACHINE = "^rpi$"

#Be able to generate QT5 sdk
#inherit populate_sdk_qt5
IMAGE_INSTALL += "rsync"

#IMAGE_FSTYPES += "rpi-sdimg"
RM_OLD_IMAGE = "1"
IMAGE_FEATURES_remove += "splash"
do_rootfs_append(){
    bb.warn("image build 900772!")
}


IMAGE_FEATURES += "ssh-server-dropbear"
IMAGE_INSTALL += "linux-firmware-bcm43430"
IMAGE_INSTALL += "kernel-modules"

#add package managment
EXTRA_IMAGE_FEATURES += "package-management"
PACKAGE_CLASS = "package_rpm"


#INSTALL i2c-tools
#IMAGE_INSTALL += "i2c-tools"
#INSTALL vim
#IMAGE_INSTALL += "vim"

#INSTALL network
IMAGE_INSTALL += "networkmanager \
 networkmanager-nmtui \
 networkmanager-bash-completion \
 "
#

#install app 
#IMAGE_INSTALL += "hello-world-cpp-sources"
#IMAGE_INSTALL += "hello-world-cpp-makefile"
#IMAGE_INSTALL += "python-flask-hello-world"
#IMAGE_INSTALL += "custom-app"
IMAGE_INSTALL += "cinematicexperience"
