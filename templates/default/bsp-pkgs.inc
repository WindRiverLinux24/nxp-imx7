IMAGE_INSTALL += "i2c-tools"
IMAGE_INSTALL += "can-utils"
IMAGE_INSTALL += "pm-utils"
IMAGE_INSTALL += "alsa-utils"
IMAGE_INSTALL += "mtdev"
IMAGE_INSTALL += "u-boot-imx"
IMAGE_INSTALL += "linux-firmware-imx-sdma-imx7d"
IMAGE_INSTALL += "openssl-engines"

NXP_IMX7_WIC_INC ?= ""
NXP_IMX7_WIC_INC:nxp-imx7 = "make_nxp_imx7_wic.inc"
require conf/${NXP_IMX7_WIC_INC}
