/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(GD_GPL)
 */

#ifndef __PLAT_MACHINE_H
#define __PLAT_MACHINE_H

#define PIC_IRQ_LINES 16
#define IOAPIC_IRQ_LINES 24

/* interrupt vectors (corresponds to IDT entries) */

#define IRQ_INT_OFFSET 0x20

typedef enum _interrupt_t {
    int_invalid                 = -1,
    int_debug                   = 1,
    int_software_break_request  = 3,
    int_unimpl_dev              = 7,
    int_gp_fault                = 13,
    int_page_fault              = 14,
    int_irq_min                 = IRQ_INT_OFFSET, /* First IRQ. */
    int_irq_isa_min             = IRQ_INT_OFFSET, /* Beginning of PIC IRQs */
    int_irq_isa_max             = IRQ_INT_OFFSET + PIC_IRQ_LINES - 1, /* End of PIC IRQs */
    int_irq_user_min            = IRQ_INT_OFFSET + PIC_IRQ_LINES, /* First user available vector */
    int_irq_user_max            = 155,
#ifdef CONFIG_IOMMU
    int_iommu                   = 156,
#endif
    int_timer                   = 157,
#ifdef ENABLE_SMP_SUPPORT
    int_remote_call_ipi         = 158,
    int_reschedule_ipi          = 159,
    int_irq_max                 = 159, /* int_reschedule_ipi is the max irq */
#else
    int_irq_max                 = 157, /* int_timer is the max irq */
#endif
    int_trap_min,
    int_trap_max                = 254,
    int_spurious                = 255,
    int_max                     = 255
} interrupt_t;

typedef enum _irq_t {
    irqInvalid                  = -1,
    irq_isa_min                 = int_irq_isa_min     - IRQ_INT_OFFSET,
    irq_isa_max                 = int_irq_isa_max     - IRQ_INT_OFFSET,
    irq_user_min                = int_irq_user_min    - IRQ_INT_OFFSET,
    irq_user_max                = int_irq_user_max    - IRQ_INT_OFFSET,
#ifdef CONFIG_IOMMU
    irq_iommu                   = int_iommu           - IRQ_INT_OFFSET,
#endif
    irq_timer                   = int_timer           - IRQ_INT_OFFSET,
#ifdef ENABLE_SMP_SUPPORT
    irq_remote_call_ipi         = int_remote_call_ipi - IRQ_INT_OFFSET,
    irq_reschedule_ipi          = int_reschedule_ipi  - IRQ_INT_OFFSET,
#endif
    maxIRQ                      = int_irq_max         - IRQ_INT_OFFSET
} irq_t;

#define IRQ_CNODE_BITS 13

#define BIOS_PADDR_START 0x0e0000
#define BIOS_PADDR_END   0x100000

#define BIOS_PADDR_VIDEO_RAM_START 0x000A0000
/* The text mode framebuffer exists part way into the video ram region */
#define BIOS_PADDR_VIDEO_RAM_TEXT_MODE_START 0x000B8000
#define BIOS_PADDR_IVDEO_RAM_END 0x000C0000

#endif
