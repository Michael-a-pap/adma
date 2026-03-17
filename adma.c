#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/interrupt.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/of_platform.h>

#define COMPATIBLE_STRING "map,fpga_dma"
#define MODULE_NAME "fpga_dma"


static int probe_adma(struct platform_device *pdev)
{
	pr_info("Module is probed by an overlay\n");
	return 0;
}

static int remove_adma(struct platform_device *pdev)
{
	pr_info("Overlay is removed\n");
	return 0;
}

static const struct of_device_id adma_of_match[] = {
	{ .compatible = COMPATIBLE_STRING, },
	{}
};
MODULE_DEVICE_TABLE(of, adma_of_match);

static struct platform_driver adma_driver = {
	.probe = probe_adma,
	.remove = remove_adma,
	.driver = {
		.name = MODULE_NAME,
		.of_match_table = adma_of_match,
	},
};

static int __init init_adma(void)
{
	pr_info("Hello world with prob\n");
	return platform_driver_register(&adma_driver);
}

static void __exit exit_adma(void)
{
	pr_info("Goodbye cruel world!\n");
}
module_init(init_adma);
module_exit(exit_adma);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Michael A. Papachatzakis");
MODULE_DESCRIPTION("Kernel module for the accelerator DMA");
