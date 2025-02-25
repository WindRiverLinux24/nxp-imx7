#
# Copyright (C) 2022 Wind River Systems, Inc.
#

COMPATIBLE_MACHINE:nxp-imx7 = "nxp-imx7"
TARGET_SUPPORTED_KTYPES:nxp-imx7 = "standard preempt-rt"

FILESEXTRAPATHS:prepend:nxp-imx7 := "${THISDIR}/files:"
SRC_URI:append:nxp-imx7 = " \
    file://0001-Revert-PCI-imx6-Skip-controller_id-generation-logic-.patch \
"
