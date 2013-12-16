#ifndef MSR_SUPPLEMENTAL_H
#define MSR_SUPPLEMENTAL_H

/* TLCC2 machines are based on Sandy Bridge Server processors, family 06 model 2D.*/

#ifdef _USE_ARCH_062D

#define PERM_OFFSET (15)
#define SMSR_RO (0<<PERM_OFFSET)
#define SMSR_RW (1<<PERM_OFFSET)
#define SMSR_REG_MASK (0xFFF)
#define SMSR_RW_MASK SMSR_RW


/* The Whitelist.
 *
 * 1) Things that access or modify interrupts are considered exploitable.
 * 	Don't allow access to temperature thresholds, interrupt vectors, etc.
 *
 * 2) Debugging features are problematic as they might allow the user access 
 * 	to kernel memory.
 *
 * 3) Writing records to DRAM (a la PEBS) needs a dedicated interface.
 * 	Don't put it here.
 *
 * 4) Anything that affects performance needs to be reset on program exit.
 *
 * 5) Performance counters should be zeroed out and disabled.
 *
 * 6) If we don't see an immediate need for access to an MSR, leave it out.
 */

//				bits    0-11    16	
//
//						perm	
//						0=ro	
// Name					Address 1=rw	
//------------------------------------------------------


// MSRs taken from section 35.8 table 35-12
#define SMSR_ENTRIES \
SMSR_ENTRY( NO_SUCH_SMSR,			0x000 | SMSR_RO),\
SMSR_ENTRY( SMSR_TIME_STAMP_COUNTER,		0x010 |	SMSR_RO),\
SMSR_ENTRY( SMSR_PLATFORM_ID,			0x017 |	SMSR_RO),\
SMSR_ENTRY( SMSR_PMC0,				0x0C1 |	SMSR_RW),\
SMSR_ENTRY( SMSR_PMC1,				0x0C2 |	SMSR_RW),\
SMSR_ENTRY( SMSR_PMC2,				0x0C3 |	SMSR_RW),\
SMSR_ENTRY( SMSR_PMC3,				0x0C4 |	SMSR_RW),\
SMSR_ENTRY( SMSR_PMC4,				0x0C5 |	SMSR_RW),\
SMSR_ENTRY( SMSR_PMC5,				0x0C6 |	SMSR_RW),\
SMSR_ENTRY( SMSR_PMC6,				0x0C7 |	SMSR_RW),\
SMSR_ENTRY( SMSR_PMC7,				0x0C8 |	SMSR_RW),\
SMSR_ENTRY( SMSR_MPERF,				0x0E7 |	SMSR_RO),\
SMSR_ENTRY( SMSR_APERF,				0x0E8 |	SMSR_RO),\
SMSR_ENTRY( SMSR_PERFEVTSEL0,			0x186 |	SMSR_RW),\
SMSR_ENTRY( SMSR_PERFEVTSEL1,			0x187 |	SMSR_RW),\
SMSR_ENTRY( SMSR_PERFEVTSEL2,			0x188 |	SMSR_RW),\
SMSR_ENTRY( SMSR_PERFEVTSEL3,			0x189 |	SMSR_RW),\
SMSR_ENTRY( SMSR_PERFEVTSEL4,			0x18A |	SMSR_RW),\
SMSR_ENTRY( SMSR_PERFEVTSEL5,			0x18B |	SMSR_RW),\
SMSR_ENTRY( SMSR_PERFEVTSEL6,			0x18C |	SMSR_RW),\
SMSR_ENTRY( SMSR_PERFEVTSEL7,			0x18D |	SMSR_RW),\
SMSR_ENTRY( SMSR_PERF_STATUS,			0x198 |	SMSR_RO),\
SMSR_ENTRY( SMSR_PERF_CTL,			0x199 |	SMSR_RW),\
SMSR_ENTRY( SMSR_CLOCK_MODULATION,		0x19A |	SMSR_RW),\
SMSR_ENTRY( SMSR_THERM_STATUS,			0x19C |	SMSR_RO),\
SMSR_ENTRY( SMSR_MISC_ENABLE,			0x1A0 |	SMSR_RW),\
SMSR_ENTRY( SMSR_OFFCORE_RSP_0,			0x1A6 |	SMSR_RW),\
SMSR_ENTRY( SMSR_OFFCORE_RSP_1,			0x1A7 |	SMSR_RW),\
SMSR_ENTRY( SMSR_ENERGY_PERF_BIAS,		0x1B0 |	SMSR_RW),\
SMSR_ENTRY( SMSR_PACKAGE_THERM_STATUS,		0x1B1 |	SMSR_RO),\
SMSR_ENTRY( SMSR_FIXED_CTR0,			0x309 |	SMSR_RW),\
SMSR_ENTRY( SMSR_FIXED_CTR1,			0x30A |	SMSR_RW),\
SMSR_ENTRY( SMSR_FIXED_CTR2,			0x30A |	SMSR_RW),\
SMSR_ENTRY( SMSR_PERF_CAPABILITIES,		0x345 |	SMSR_RO),\
SMSR_ENTRY( SMSR_FIXED_CTR_CTRL,		0x38D |	SMSR_RW),\
SMSR_ENTRY( SMSR_PERF_GLOBAL_STATUS,		0x38E |	SMSR_RO),\
SMSR_ENTRY( SMSR_PERF_GLOBAL_CTRL,		0x38F |	SMSR_RW),\
SMSR_ENTRY( SMSR_PERF_GLOBAL_OVF_CTRL,		0x390 |	SMSR_RW),\
SMSR_ENTRY( SMSR_PEBS_ENABLE,			0x3F1 |	SMSR_RW),\
SMSR_ENTRY( SMSR_PEBS_LD_LAT,			0x3F6 |	SMSR_RW),\
SMSR_ENTRY( SMSR_RAPL_POWER_UNIT,		0x606 |	SMSR_RO),\
SMSR_ENTRY( SMSR_PKG_POWER_LIMIT,		0x610 |	SMSR_RW),\
SMSR_ENTRY( SMSR_PKG_ENERGY_STATUS,		0x611 |	SMSR_RO),\
SMSR_ENTRY( SMSR_PKG_POWER_INFO,		0x612 |	SMSR_RO),\
SMSR_ENTRY( SMSR_PP0_POWER_LIMIT,		0x638 |	SMSR_RW),\
SMSR_ENTRY( SMSR_PP0_ENERGY_STATUS,		0x639 |	SMSR_RO),\
SMSR_ENTRY( SMSR_MSR_PKG_PERF_STATUS,		0x613 |	SMSR_RO),\
SMSR_ENTRY( SMSR_DRAM_POWER_LIMIT,		0x618 |	SMSR_RW),\
SMSR_ENTRY( SMSR_DRAM_ENERGY_STATUS,		0x619 |	SMSR_RO),\
SMSR_ENTRY( SMSR_DRAM_PERF_STATUS,		0x61B |	SMSR_RO),\
SMSR_ENTRY( SMSR_DRAM_POWER_INFO,		0x61C |	SMSR_RO),\
SMSR_ENTRY( SMSR_LAST_ENTRY, 			0x000 | SMSR_RO)

#endif //_USE_ARCH_062D

#endif /* MSR_SUPPLEMENTAL_H */
