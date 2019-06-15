#!/bin/sh

export USE_CCACHE=1

export CACHE_DIR=~/.ccache

export KBUILD_BUILD_USER=Ab.Shaheen
export KBUILD_BUILD_HOST=BuildHost

export ARCH=arm64

# linaro GCC 6.5
# export CROSS_COMPILE=aarch64-linux-gnu-
# export PATH=/home/abuzar/Kernel/GCC/gcc-linaro-6.5.0-2018.12-i686_aarch64-linux-gnu/bin/:$PATH

# linaro working GCC
# export CROSS_COMPILE=aarch64-linaro-linux-android-
# export PATH=/home/abuzar/Kernel/GCC/gcc-prebuilts/bin/:$PATH

# linaro updated GCC
# export CROSS_COMPILE=aarch64-common-linux-android-
# export PATH=/home/abuzar/Kernel/linaro-arm64/bin/:$PATH

# havoc GCC
export CROSS_COMPILE=aarch64-linux-android-
export PATH=/home/abuzar/havoc/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin:$PATH

make lineageos_h930_defconfig

time make -j8

mkbootimg --kernel /home/abuzar/Kernel/markus/arch/arm64/boot/Image.gz-dtb --ramdisk /home/abuzar/Kernel/boot.img-ramdisk.cpio.gz --second /dev/null --cmdline "androidboot.hardware=joan user_debug=31 msm_rtb.filter=0x37 ehci-hcd.park=3 lpm_levels.sleep_disabled=1 sched_enable_hmp=1 sched_enable_power_aware=1 service_locator.enable=1 swiotlb=2048 rcupdate.rcu_expedited=1 androidboot.configfs=true androidboot.usbcontroller=a800000.dwc3 androidboot.selinux=permissive buildvariant=userdebug" --base 0x00000000 --board "" --pagesize 4096 -o /home/abuzar/Kernel/markus/boot.img
