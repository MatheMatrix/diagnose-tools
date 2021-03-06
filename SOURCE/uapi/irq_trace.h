/*
 * Linux内核诊断工具--用户接口API
 *
 * Copyright (C) 2020 Alibaba Ltd.
 *
 * 作者: Baoyou Xie <baoyou.xie@linux.alibaba.com>
 *
 * License terms: GNU General Public License (GPL) version 3
 *
 */

#ifndef UAPI_IRQ_TRACE_H
#define UAPI_IRQ_TRACE_H

int irq_trace_syscall(struct pt_regs *regs, long id);

//#define DIAG_IRQ_TRACE_ACTIVATE (DIAG_BASE_SYSCALL_IRQ_TRACE)
//#define DIAG_IRQ_TRACE_DEACTIVATE (DIAG_IRQ_TRACE_ACTIVATE + 1)
#define DIAG_IRQ_TRACE_SET (DIAG_BASE_SYSCALL_IRQ_TRACE)
#define DIAG_IRQ_TRACE_SETTINGS (DIAG_IRQ_TRACE_SET + 1)
#define DIAG_IRQ_TRACE_DUMP (DIAG_IRQ_TRACE_SETTINGS + 1)

struct diag_irq_trace_settings {
	unsigned int activated;
	unsigned int verbose;
	unsigned long threshold_irq, threshold_sirq, threshold_timer;
};

struct irq_trace_detail {
	int et_type;
	struct timeval tv;
	int cpu;
	int source;
	void *func;
	unsigned long time;
};

struct irq_trace_sum {
	int et_type;
	struct timeval tv;
	unsigned long irq_count;
	unsigned long irq_runs;
	unsigned long sirq_count[DIAG_NR_SOFTIRQS];
	unsigned long sirq_runs[DIAG_NR_SOFTIRQS];
	unsigned long timer_count;
	unsigned long timer_runs;
};

#endif /* UAPI_IRQ_TRACE_H */
