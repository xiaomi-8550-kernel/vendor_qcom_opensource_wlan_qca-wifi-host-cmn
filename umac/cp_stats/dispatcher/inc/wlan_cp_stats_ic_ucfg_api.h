/*
 * Copyright (c) 2018 The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/**
 * DOC: wlan_cp_stats_ic_ucfg_api.h
 *
 */

#ifndef __WLAN_CP_STATS_IC_UCFG_API_H__
#define __WLAN_CP_STATS_IC_UCFG_API_H__

#ifdef QCA_SUPPORT_CP_STATS
#include <wlan_objmgr_cmn.h>
#include <wlan_cp_stats_ic_defs.h>
#include "../../core/src/wlan_cp_stats_defs.h"

#define UCFG_PEER_CP_STATS_SET_FUNCS(field) \
	static inline void \
	ucfg_peer_cp_stats_##field##_inc(struct wlan_objmgr_peer *_peer, \
					 uint32_t _val) \
	{ \
		struct peer_cp_stats *_peer_cs = \
			wlan_cp_stats_get_peer_stats_obj(_peer); \
		if (_peer_cs) { \
			struct peer_ic_cp_stats *_peer_ics = \
						_peer_cs->peer_stats; \
			if (_peer_ics) { \
				_peer_ics->cs_##field += _val;\
			} \
		} \
	} \
	static inline void \
	ucfg_peer_cp_stats_##field##_dec(struct wlan_objmgr_peer *_peer, \
					 uint32_t _val) \
	{ \
		struct peer_cp_stats *_peer_cs = \
			wlan_cp_stats_get_peer_stats_obj(_peer); \
		if (_peer_cs) { \
			struct peer_ic_cp_stats *_peer_ics = \
						_peer_cs->peer_stats; \
			if (_peer_ics) { \
				_peer_ics->cs_##field -= _val;\
			} \
		} \
	} \
	static inline void \
	ucfg_peer_cp_stats_##field##_update(struct wlan_objmgr_peer *_peer, \
					    uint32_t _val) \
	{ \
		struct peer_cp_stats *_peer_cs = \
				wlan_cp_stats_get_peer_stats_obj(_peer); \
		if (_peer_cs) { \
			struct peer_ic_cp_stats *_peer_ics = \
							_peer_cs->peer_stats; \
			if (_peer_ics) { \
				_peer_ics->cs_##field = _val;\
			} \
		} \
	}

UCFG_PEER_CP_STATS_SET_FUNCS(rx_mgmt);
UCFG_PEER_CP_STATS_SET_FUNCS(tx_mgmt);
UCFG_PEER_CP_STATS_SET_FUNCS(rx_mgmt_rate);
UCFG_PEER_CP_STATS_SET_FUNCS(is_tx_not_ok);
UCFG_PEER_CP_STATS_SET_FUNCS(rx_noprivacy);
UCFG_PEER_CP_STATS_SET_FUNCS(rx_wepfail);
UCFG_PEER_CP_STATS_SET_FUNCS(rx_tkipicv);
UCFG_PEER_CP_STATS_SET_FUNCS(rx_wpimic);
UCFG_PEER_CP_STATS_SET_FUNCS(rx_ccmpmic);
UCFG_PEER_CP_STATS_SET_FUNCS(ps_discard);
UCFG_PEER_CP_STATS_SET_FUNCS(psq_drops);
UCFG_PEER_CP_STATS_SET_FUNCS(tx_assoc);
UCFG_PEER_CP_STATS_SET_FUNCS(tx_assoc_fail);
#ifdef ATH_SUPPORT_IQUE
UCFG_PEER_CP_STATS_SET_FUNCS(tx_dropblock);
#endif
#ifdef WLAN_ATH_SUPPORT_EXT_STAT
UCFG_PEER_CP_STATS_SET_FUNCS(tx_bytes_rate);
UCFG_PEER_CP_STATS_SET_FUNCS(rx_bytes_rate);
UCFG_PEER_CP_STATS_SET_FUNCS(tx_data_rate);
UCFG_PEER_CP_STATS_SET_FUNCS(rx_data_rate);
UCFG_PEER_CP_STATS_SET_FUNCS(rx_bytes_last);
UCFG_PEER_CP_STATS_SET_FUNCS(rx_data_last);
UCFG_PEER_CP_STATS_SET_FUNCS(tx_bytes_success_last);
UCFG_PEER_CP_STATS_SET_FUNCS(tx_data_success_last);
#endif

static inline
void ucfg_peer_cp_stats_rx_mgmt_rssi_update(struct wlan_objmgr_peer *peer,
					    int8_t rssi)
{
	struct peer_cp_stats *peer_cs;
	struct peer_ic_cp_stats *peer_cps;

	if (!peer)
		return;

	peer_cs = wlan_cp_stats_get_peer_stats_obj(peer);
	if (!peer_cs)
		return;

	peer_cps = peer_cs->peer_stats;
	if (peer_cps)
		peer_cps->cs_rx_mgmt_rssi = rssi;
}

static inline
int8_t ucfg_peer_cp_stats_rx_mgmt_rssi_get(struct wlan_objmgr_peer *peer)
{
	struct peer_cp_stats *peer_cs;
	struct peer_ic_cp_stats *peer_cps;
	int8_t val = -1;

	if (!peer)
		return val;

	peer_cs = wlan_cp_stats_get_peer_stats_obj(peer);
	if (!peer_cs)
		return val;

	peer_cps = peer_cs->peer_stats;
	if (peer_cps)
		val = peer_cps->cs_rx_mgmt_rssi;

	return val;
}

#define UCFG_PEER_CP_STATS_GET_FUNCS(field) \
	static inline uint32_t \
	ucfg_peer_cp_stats_##field##_get(struct wlan_objmgr_peer *_peer) \
	{ \
		struct peer_cp_stats *_peer_cs = \
				wlan_cp_stats_get_peer_stats_obj(_peer); \
		struct peer_ic_cp_stats *_peer_ics; \
		if (_peer_cs) { \
			_peer_ics = _peer_cs->peer_stats; \
			if (_peer_ics) \
				return  _peer_ics->cs_##field; \
		} \
		return 0; \
	}

UCFG_PEER_CP_STATS_GET_FUNCS(rx_mgmt_rate);
#ifdef ATH_SUPPORT_IQUE
UCFG_PEER_CP_STATS_GET_FUNCS(tx_dropblock);
#endif

/**
 * wlan_ucfg_get_peer_cp_stats() - ucfg API to get peer cp stats
 * @peer_obj: pointer to peer object
 * @peer_cps: pointer to peer cp stats object to populate
 *
 * Return: QDF_STATUS - Success or Failure
 */
QDF_STATUS wlan_ucfg_get_peer_cp_stats(struct wlan_objmgr_peer *peer,
				       struct peer_ic_cp_stats *peer_cps);

#endif /* QCA_SUPPORT_CP_STATS */
#endif /* __WLAN_CP_STATS_IC_UCFG_API_H__ */
