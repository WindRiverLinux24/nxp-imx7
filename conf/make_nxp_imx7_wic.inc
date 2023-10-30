do_image_wic[postfuncs] += "nxp_imx7_wic"

nxp_imx7_wic() {
    for config in imx7d-sdb; do
        cd "${DEPLOY_DIR_IMAGE}"

        ofname=${IMAGE_LINK_NAME}-${config}${IMAGE_VERSION_SUFFIX}.rootfs.wic
        cp ${IMGDEPLOYDIR}/${IMAGE_LINK_NAME}.wic ${IMGDEPLOYDIR}/$ofname
        dd if=u-boot.imx-sd of=${IMGDEPLOYDIR}/$ofname bs=512 seek=2 conv=fsync,notrunc

        cd "${IMGDEPLOYDIR}"
        bmaptool create "$ofname" -o "${ofname}.bmap"
        linkname="${IMAGE_LINK_NAME}-${config}.wic"
        ln -sf $ofname $linkname
    done

    # Remove the default wic file
    rm -rf "${IMGDEPLOYDIR}/${IMAGE_LINK_NAME}.wic"
    rm -rf "${IMGDEPLOYDIR}/${IMAGE_LINK_NAME}.wic.bmap"
    rm -rf "${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.wic"
    rm -rf "${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.wic.bmap"
}
