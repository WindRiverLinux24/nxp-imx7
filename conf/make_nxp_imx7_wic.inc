do_image_wic[postfuncs] += "nxp_imx7_wic"

nxp_imx7_wic() {
    for config in imx7d-sdb; do
        cd "${DEPLOY_DIR_IMAGE}"

        cp ${IMGDEPLOYDIR}/${IMAGE_LINK_NAME}.wic ${IMGDEPLOYDIR}/${IMAGE_LINK_NAME}-${config}.wic
        dd if=u-boot.imx-sd of=${IMGDEPLOYDIR}/${IMAGE_LINK_NAME}-${config}.wic bs=512 seek=2 conv=fsync,notrunc

        cd "${IMGDEPLOYDIR}"
        bmaptool create "${IMAGE_LINK_NAME}-${config}.wic" -o "${IMAGE_LINK_NAME}-${config}.wic.bmap"
    done

    # Remove the default wic file
    rm -rf "${IMGDEPLOYDIR}/${IMAGE_LINK_NAME}.wic"
    rm -rf "${IMGDEPLOYDIR}/${IMAGE_LINK_NAME}.wic.bmap"
    rm -rf "${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.wic"
    rm -rf "${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.wic.bmap"
}
