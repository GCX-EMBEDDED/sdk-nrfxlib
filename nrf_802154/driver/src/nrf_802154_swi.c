/*
 * Copyright (c) 2017 - 2022, Nordic Semiconductor ASA
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 * @file
 *   This file implements SWI manager for nRF 802.15.4 driver.
 *
 */

#include "nrf_802154_swi.h"

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

#include "compiler_abstraction.h"
#include "nrf_802154.h"
#include "nrf_802154_config.h"
#include "nrf_802154_peripherals.h"
#include "platform/nrf_802154_irq.h"

#if NRF_802154_INTERNAL_SWI_IRQ_HANDLING
/* SWI interrupt handling functionality is implemented directly by the chosen EGU IRQ handler. */
#define SWI_IRQHandler NRF_802154_EGU_IRQ_HANDLER ///< Symbol of SWI IRQ handler.
#else
#define SWI_IRQHandler nrf_802154_swi_irq_handler ///< Symbol of SWI IRQ handler.
#endif

__WEAK void nrf_802154_trx_swi_irq_handler(void)
{
    /* Implementation provided by other module if necessary */
}

__WEAK void nrf_802154_notification_swi_irq_handler(void)
{
    /* Implementation provided by other module if necessary */
}

__WEAK void nrf_802154_rsch_prio_drop_swi_irq_handler(void)
{
    /* Implementation provided by other module if necessary */
}

__WEAK void nrf_802154_request_swi_irq_handler(void)
{
    /* Implementation provided by other module if necessary */
}

static void swi_irq_handler(void)
{
    nrf_802154_trx_swi_irq_handler();
    nrf_802154_notification_swi_irq_handler();
    nrf_802154_rsch_prio_drop_swi_irq_handler();
    nrf_802154_request_swi_irq_handler();
}

void nrf_802154_swi_init(void)
{
    static bool initialized = false;

    if (!initialized)
    {
        nrf_802154_irq_init(NRF_802154_EGU_IRQN, NRF_802154_SWI_PRIORITY, swi_irq_handler);
        nrf_802154_irq_enable(NRF_802154_EGU_IRQN);
        initialized = true;
    }
}

void SWI_IRQHandler(void)
{
    swi_irq_handler();
}
