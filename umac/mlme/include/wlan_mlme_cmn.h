/*
 * Copyright (c) 2019-2020 The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/**
 * DOC: Define Common MLME structure and APIs
 */
#ifndef _WLAN_MLME_CMN_H_
#define _WLAN_MLME_CMN_H_

#include <include/wlan_psoc_mlme.h>
#include <include/wlan_pdev_mlme.h>
#include <include/wlan_vdev_mlme.h>
#ifdef FEATURE_CM_ENABLE
#include "wlan_cm_public_struct.h"
#endif

#ifdef FEATURE_CM_ENABLE

/**
 * mlme_cm_ops: connection manager callbacks
 * @mlme_cm_connect_complete_cb:       Connect done callback
 * @vdev: vdev pointer
 * @cm_conn_rsp: connect response
 *
 * @mlme_cm_failed_candidate_cb:       Callback to indicate failed candidate
 * @vdev: vdev pointer
 * @cm_conn_rsp: connect response
 *
 * @mlme_cm_update_conn_id_and_src_cb: Callback to update connect id and
 *                                     source of the connect request
 * @vdev: vdev pointer
 * @Source: Source of the connect req
 * @conn_id: Connect id
 *
 * @mlme_cm_disconnect_complete_cb:    Disconnect done callback
 * @vdev: vdev pointer
 * @cm_disconnect_rsp: Disconnect response
 *
 * @mlme_cm_disconnect_start_cb:       Disconnect start callback
 * @vdev: vdev pointer
 */
struct mlme_cm_ops {
	void (*mlme_cm_connect_complete_cb)(
				struct wlan_objmgr_vdev *vdev,
				struct wlan_cm_connect_rsp *cm_conn_rsp);
	void (*mlme_cm_failed_candidate_cb)(
				struct wlan_objmgr_vdev *vdev,
				struct wlan_cm_connect_rsp *cm_conn_rsp);
	void (*mlme_cm_update_conn_id_and_src_cb)(
						struct wlan_objmgr_vdev *vdev,
						enum wlan_cm_source source,
						uint64_t conn_id);
	void (*mlme_cm_disconnect_complete_cb)(
				struct wlan_objmgr_vdev *vdev,
				struct wlan_cm_discon_rsp *cm_disconn_rsp);
	void (*mlme_cm_disconnect_start_cb)(struct wlan_objmgr_vdev *vdev);
};
#endif

/**
 * struct vdev_mlme_ext_ops - VDEV MLME legacy callbacks structure
 * @mlme_psoc_ext_hdl_create:        callback to invoke creation of legacy
 *                                   psoc object
 * @mlme_psoc_ext_hdl_destroy:       callback to invoke destroy of legacy
 *                                   psoc object
 * @mlme_pdev_ext_hdl_create:        callback to invoke creation of legacy
 *                                   pdev object
 * @mlme_pdev_ext_hdl_destroy:       callback to invoke destroy of legacy
 *                                   pdev object
 * @mlme_vdev_ext_hdl_create:        callback to invoke creation of legacy
 *                                   vdev object
 * @mlme_vdev_ext_hdl_post_create:   callback to invoke post creation actions
 *                                   of legacy vdev object
 * @mlme_vdev_ext_hdl_destroy:       callback to invoke destroy of legacy
 *                                   vdev object
 * @mlme_vdev_start_fw_send:         callback to invoke vdev start command
 * @mlme_vdev_stop_fw_send:          callback to invoke vdev stop command
 * @mlme_vdev_down_fw_send:          callback to invoke vdev down command
 * @mlme_multivdev_restart_fw_send:  callback to invoke multivdev restart
 *                                   command
 * @mlme_vdev_enqueue_exp_cmd:       callback to enqueue exception command
 *                                   required by serialization
 * @mlme_multi_vdev_restart_resp:    callback to process multivdev restart
 *				     response
 * @mlme_cm_ext_connect_start: Callback to start connect request
 * @mlme_cm_ext_connect_active: Callback to indicate connect active
 * @mlme_cm_ext_bss_peer_create_req: Callback to bss peer create request
 * @mlme_cm_ext_connect_req: Callback for connect request to LIM
 * @mlme_cm_ext_connect_complete: Callback to indicate connect complete
 * @mlme_cm_ext_disconnect_start : Callback to start disconnect request
 * @mlme_cm_ext_disconnect_active: Callback to indicate disconnect active
 * @mlme_cm_ext_bss_peer_delete_req: Callback to bss peer delete request
 * @mlme_cm_ext_disconnect_complete: Callback to indicate disconnect
 *                                        complete
 * @mlme_cm_ext_osif_connect: Callback to indicate connect complete
 * @mlme_cm_ext_osif_disconnect: Callback to indicate disconnect complete
 * @mlme_cm_ext_vdev_down: Callback to send vdev down to FW
 */
struct mlme_ext_ops {
	QDF_STATUS (*mlme_psoc_ext_hdl_create)(
				struct psoc_mlme_obj *psoc_mlme);
	QDF_STATUS (*mlme_psoc_ext_hdl_destroy)(
				struct psoc_mlme_obj *pdev_mlme);
	QDF_STATUS (*mlme_pdev_ext_hdl_create)(
				struct pdev_mlme_obj *pdev_mlme);
	QDF_STATUS (*mlme_pdev_ext_hdl_destroy)(
				struct pdev_mlme_obj *pdev_mlme);
	QDF_STATUS (*mlme_vdev_ext_hdl_create)(
				struct vdev_mlme_obj *vdev_mlme);
	QDF_STATUS (*mlme_vdev_ext_hdl_post_create)(
				struct vdev_mlme_obj *vdev_mlme);
	QDF_STATUS (*mlme_vdev_ext_hdl_destroy)(
				struct vdev_mlme_obj *vdev_mlme);
	QDF_STATUS (*mlme_vdev_start_fw_send)(
				struct wlan_objmgr_vdev *vdev, uint8_t restart);
	QDF_STATUS (*mlme_vdev_stop_fw_send)(struct wlan_objmgr_vdev *vdev);
	QDF_STATUS (*mlme_vdev_down_fw_send)(struct wlan_objmgr_vdev *vdev);
	QDF_STATUS (*mlme_multivdev_restart_fw_send)(
				struct wlan_objmgr_pdev *pdev);
	QDF_STATUS (*mlme_vdev_enqueue_exp_cmd)(
				struct vdev_mlme_obj *vdev_mlme,
				uint8_t cmd_type);
	QDF_STATUS (*mlme_vdev_ext_delete_rsp)(
					   struct wlan_objmgr_psoc *psoc,
					   struct vdev_delete_response *rsp);
	QDF_STATUS (*mlme_multi_vdev_restart_resp)(
				struct wlan_objmgr_psoc *psoc,
				struct multi_vdev_restart_resp *resp);
#ifdef FEATURE_CM_ENABLE
	QDF_STATUS (*mlme_cm_ext_connect_start)(
				struct wlan_objmgr_vdev *vdev,
				struct wlan_cm_connect_req *cm_conn_req);
	QDF_STATUS (*mlme_cm_ext_connect_active)(
			struct wlan_objmgr_vdev *vdev,
			struct wlan_cm_vdev_connect_req *vdev_connect_req);
	QDF_STATUS (*mlme_cm_ext_bss_peer_create_req)(
				struct wlan_objmgr_vdev *vdev,
				struct qdf_mac_addr *peer_mac);
	QDF_STATUS (*mlme_cm_ext_connect_req)(
			struct wlan_objmgr_vdev *vdev,
			struct wlan_cm_vdev_connect_req *vdev_connect_req);
	QDF_STATUS (*mlme_cm_ext_connect_complete)(
				struct wlan_objmgr_vdev *vdev,
				struct wlan_cm_connect_rsp *connect_rsp);
	QDF_STATUS (*mlme_cm_ext_disconnect_start)(
				struct wlan_objmgr_vdev *vdev,
				struct wlan_cm_disconnect_req *cm_conn_req);
	QDF_STATUS (*mlme_cm_ext_disconnect_active)
			(struct wlan_objmgr_vdev *vdev,
			struct wlan_cm_vdev_discon_req *vdev_disconnect_req);
	QDF_STATUS (*mlme_cm_ext_bss_peer_delete_req)(
			struct wlan_objmgr_vdev *vdev);
	QDF_STATUS (*mlme_cm_ext_disconnect_complete)(
				struct wlan_objmgr_vdev *vdev,
				struct wlan_cm_discon_rsp *cm_disconnect_rsp);
	QDF_STATUS (*mlme_cm_ext_osif_connect)(
				struct wlan_objmgr_vdev *vdev,
				struct wlan_cm_connect_rsp *cm_connect_rsp);
	QDF_STATUS (*mlme_cm_ext_osif_disconnect)(
				struct wlan_objmgr_vdev *vdev,
				struct wlan_cm_discon_rsp *cm_disconnect_rsp);
	QDF_STATUS (*mlme_cm_ext_vdev_down)(
				struct wlan_objmgr_vdev *vdev);
#endif
};

/**
 * mlme_psoc_ops_ext_hdl_create() - Alloc PSOC mlme ext handle
 * @psoc_mlme:  PSOC MLME comp object
 *
 * API to allocate PSOC MLME ext handle
 *
 * Return: SUCCESS on successful allocation
 *         Else FAILURE
 */
QDF_STATUS mlme_psoc_ops_ext_hdl_create(struct psoc_mlme_obj *psoc_mlme);

/**
 * mlme_psoc_ops_ext_hdl_destroy() - Destroy PSOC mlme ext handle
 * @psoc_mlme:  PSOC MLME comp object
 *
 * API to free psoc MLME ext handle
 *
 * Return: SUCCESS on successful free
 *         Else FAILURE
 */
QDF_STATUS mlme_psoc_ops_ext_hdl_destroy(struct psoc_mlme_obj *psoc_mlme);

/**
 * mlme_pdev_ops_ext_hdl_create - Alloc PDEV mlme ext handle
 * @pdev_mlme_obj:  PDEV MLME comp object
 *
 * API to allocate PDEV MLME ext handle
 *
 * Return: SUCCESS on successful allocation
 *         Else FAILURE
 */
QDF_STATUS mlme_pdev_ops_ext_hdl_create(struct pdev_mlme_obj *pdev_mlme);

/**
 * mlme_pdev_ops_ext_hdl_destroy - Destroy PDEV mlme ext handle
 * @pdev_mlme_obj:  PDEV MLME comp object
 *
 * API to free pdev MLME ext handle
 *
 * Return: SUCCESS on successful free
 *         Else FAILURE
 */
QDF_STATUS mlme_pdev_ops_ext_hdl_destroy(struct pdev_mlme_obj *pdev_mlme);

/**
 * mlme_vdev_ops_ext_hdl_create - Alloc VDEV mlme ext handle
 * @vdev_mlme_obj:  VDEV MLME comp object
 *
 * API to allocate VDEV MLME ext handle
 *
 * Return: SUCCESS on successful allocation
 *         Else FAILURE
 */
QDF_STATUS mlme_vdev_ops_ext_hdl_create(struct vdev_mlme_obj *vdev_mlme);

/**
 * mlme_vdev_ops_ext_hdl_post_create - Perform post VDEV mlme ext handle alloc
 *                                     operations
 * @vdev_mlme_obj:  VDEV MLME comp object
 *
 * API to perform post vdev MLME ext handle allocation operations
 *
 * Return: SUCCESS on initialization successful
 *         Else FAILURE
 */
QDF_STATUS mlme_vdev_ops_ext_hdl_post_create(struct vdev_mlme_obj *vdev_mlme);

/**
 * mlme_vdev_ops_ext_hdl_destroy - Destroy VDEV mlme ext handle
 * @vdev_mlme_obj:  VDEV MLME comp object
 *
 * API to free vdev MLME ext handle
 *
 * Return: SUCCESS on successful free
 *         Else FAILURE
 */
QDF_STATUS mlme_vdev_ops_ext_hdl_destroy(struct vdev_mlme_obj *vdev_mlme);

/**
 * mlme_vdev_enqueue_exp_ser_cmd - Enqueue exception serialization cmd
 * @vdev_mlme_obj:  VDEV MLME comp object
 * @cmd_type: Serialization command type
 *
 * API to enqueue the exception serialization command, used by
 * mlme-serialization wrapper layer
 *
 * Return: SUCCESS on successful enqueuing the command
 *         Else FAILURE
 */
QDF_STATUS mlme_vdev_enqueue_exp_ser_cmd(struct vdev_mlme_obj *vdev_mlme,
					 uint8_t cmd_type);

/**
 * mlme_vdev_ops_start_fw_send - Send WMI START/RESTART commmand to FW
 * @vdev:  VDEV object
 *
 * API to send WMI start/restart command to FW
 *
 * Return: SUCCESS on successful sending the command
 *         Else FAILURE
 */
QDF_STATUS mlme_vdev_ops_start_fw_send(struct wlan_objmgr_vdev *vdev,
				       uint8_t restart);

/**
 * mlme_vdev_ops_multivdev_restart_fw_cmd_send - Send WMI Multivdev restart
 *                                              commmand to FW
 * @pdev:  PDEV object
 *
 * API to send WMI multivdev restart command to FW
 *
 * Return: SUCCESS on successful sending the command
 *         Else FAILURE
 */
QDF_STATUS mlme_vdev_ops_multivdev_restart_fw_cmd_send(
						struct wlan_objmgr_pdev *pdev);

/**
 * mlme_vdev_ops_stop_fw_send - Send WMI STOP commmand to FW
 * @vdev:  VDEV object
 *
 * API to send WMI stop command to FW
 *
 * Return: SUCCESS on successful sending the command
 *         Else FAILURE
 */
QDF_STATUS mlme_vdev_ops_stop_fw_send(struct wlan_objmgr_vdev *vdev);

/**
 * mlme_vdev_ops_down_fw_send - Send WMI Down commmand to FW
 * @vdev:  VDEV object
 *
 * API to send WMI down command to FW
 *
 * Return: SUCCESS on successful sending the command
 *         Else FAILURE
 */
QDF_STATUS mlme_vdev_ops_down_fw_send(struct wlan_objmgr_vdev *vdev);

/*
 * mlme_vdev_ops_ext_hdl_multivdev_restart_resp() - Handler multivdev restart
 * response event
 * @psoc: PSOC object manager handle
 * @resp: Restart response event
 *
 * Return: Success on successful handling of the response event,
 *         Else failure
 */
QDF_STATUS mlme_vdev_ops_ext_hdl_multivdev_restart_resp(
		struct wlan_objmgr_psoc *psoc,
		struct multi_vdev_restart_resp *resp);

/**
 * mlme_set_ops_register_cb - Sets ops registration callback
 * @ops_cb:  Function pointer
 *
 * API to set ops registration call back
 *
 * Return: void
 */
typedef struct mlme_ext_ops *(*mlme_get_global_ops_cb)(void);
void mlme_set_ops_register_cb(mlme_get_global_ops_cb ops_cb);

/**
 * wlan_cmn_mlme_init - Initializes MLME component
 *
 * Registers callbacks with object manager for create/destroy
 *
 * Return: SUCCESS on successful registration
 *         FAILURE, if registration fails
 */
QDF_STATUS wlan_cmn_mlme_init(void);

/**
 * wlan_cmn_mlme_deinit - Uninitializes MLME component
 *
 * Unregisters callbacks with object manager for create/destroy
 *
 * Return: SUCCESS on successful registration
 *         FAILURE, if registration fails
 */
QDF_STATUS wlan_cmn_mlme_deinit(void);

/**
 * mlme_vdev_ops_ext_hdl_delete_rsp - Vdev Delete response ext handler
 * @psoc: PSOC object
 * @rsp: Vdev delete response received from the firmware
 *
 * API to invoke the legacy delete response handler for legacy cleanup
 *
 * Return: SUCCESS on successful deletion
 *         FAILURE, if deletion fails
 */
QDF_STATUS mlme_vdev_ops_ext_hdl_delete_rsp(struct wlan_objmgr_psoc *psoc,
					    struct vdev_delete_response *rsp);

#ifdef FEATURE_CM_ENABLE
/**
 * mlme_cm_ops_ext_connect_start - Connection manager connect start
 * handler
 * @vdev:  VDEV object
 * @req: Connection manager connect request
 *
 * Return: QDF_STATUS
 */
QDF_STATUS mlme_cm_ops_ext_connect_start(struct wlan_objmgr_vdev *vdev,
					 struct wlan_cm_connect_req *req);

/**
 * mlme_cm_ops_ext_connect_active - Connection manager indicate connect
 * active handler
 * @vdev:  VDEV object
 * @req: Vdev connect request
 *
 * Return: QDF_STATUS
 */
QDF_STATUS mlme_cm_ops_ext_connect_active(struct wlan_objmgr_vdev *vdev,
					  struct wlan_cm_vdev_connect_req *req);

/**
 * mlme_cm_ops_ext_bss_peer_create_req - Connection manager bss peer
 * create request handler
 * @vdev:  VDEV object
 * @peer_mac: Peer mac address
 *
 * Return: QDF_STATUS
 */
QDF_STATUS mlme_cm_ops_ext_bss_peer_create_req(struct wlan_objmgr_vdev *vdev,
					       struct qdf_mac_addr *peer_mac);

/**
 * mlme_cm_ops_ext_connect_req - Connection manager connect request handler
 * @vdev:  VDEV object
 * @req: Vdev connect request
 *
 * Return: QDF_STATUS
 */
QDF_STATUS mlme_cm_ops_ext_connect_req(struct wlan_objmgr_vdev *vdev,
				       struct wlan_cm_vdev_connect_req *req);

/**
 * mlme_cm_ops_ext_connect_complete - Connection manager connect complete
 * handler
 * @vdev:  VDEV object
 * @rsp: Connection manager connect response
 *
 * Return: QDF_STATUS
 */
QDF_STATUS mlme_cm_ops_ext_connect_complete(struct wlan_objmgr_vdev *vdev,
					    struct wlan_cm_connect_rsp *rsp);

/**
 * mlme_cm_ops_ext_disconnect_start - Connection manager disconnect start
 * handler
 * @vdev:  VDEV object
 * @req: Connection manager disconnect request
 *
 * Return: QDF_STATUS
 */
QDF_STATUS mlme_cm_ops_ext_disconnect_start(struct wlan_objmgr_vdev *vdev,
					    struct wlan_cm_disconnect_req *req);

/**
 * mlme_cm_ops_ext_disconnect_active - Connection manager disconnect
 * active handler
 * @vdev:  VDEV object
 * @req: vdev disconnect request
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
mlme_cm_ops_ext_disconnect_active(struct wlan_objmgr_vdev *vdev,
				  struct wlan_cm_vdev_discon_req *req);

/**
 * mlme_cm_ops_ext_bss_peer_delete_req - Connection manager bss peer delete
 * request handler
 * @vdev:  VDEV object
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
mlme_cm_ops_ext_bss_peer_delete_req(struct wlan_objmgr_vdev *vdev);

/**
 * mlme_cm_ops_ext_disconnect_complete - Connection manager disconnect
 * complete handler
 * @vdev:  VDEV object
 * @rsp: Connection manager disconnect response
 *
 * Return: QDF_STATUS
 */
QDF_STATUS mlme_cm_ops_ext_disconnect_complete(struct wlan_objmgr_vdev *vdev,
					       struct wlan_cm_discon_rsp *rsp);

/**
 * mlme_cm_ops_ext_osif_connect - Connection manager osif connect handler
 * @vdev:  VDEV object
 * @rsp: Connection manager connect response
 *
 * Return: QDF_STATUS
 */
QDF_STATUS mlme_cm_ops_ext_osif_connect(struct wlan_objmgr_vdev *vdev,
					struct wlan_cm_connect_rsp *rsp);

/**
 * mlme_cm_ops_ext_osif_disconnect - Connection manager osif disconnect
 * handler
 * @vdev:  VDEV object
 * @rsp: Connection manager disconnect response
 *
 * Return: QDF_STATUS
 */
QDF_STATUS mlme_cm_ops_ext_osif_disconnect(struct wlan_objmgr_vdev *vdev,
					   struct wlan_cm_discon_rsp *rsp);

/**
 * mlme_cm_ops_ext_osif_disconnect - Function to send vdev down to FW
 * @vdev:  VDEV object
 *
 * Return: QDF_STATUS
 */
QDF_STATUS mlme_cm_ext_vdev_down(struct wlan_objmgr_vdev *vdev);

/**
 * mlme_cm_connect_complete() - Connect response
 * @vdev: vdev pointer
 * @cm_conn_rsp: Connect response
 *
 * Return: None
 */
void mlme_cm_connect_complete(struct wlan_objmgr_vdev *vdev,
			      struct wlan_cm_connect_rsp *cm_conn_rsp);

/**
 * mlme_cm_failed_candidate() - Failed Candidate indication
 * @vdev: vdev pointer
 * @cm_conn_rsp: Connect response
 *
 * Return: None
 */
void mlme_cm_failed_candidate(struct wlan_objmgr_vdev *vdev,
			      struct wlan_cm_connect_rsp *cm_conn_rsp);

/**
 * mlme_cm_update_conn_id_and_src() - Update connection id and source
 * @vdev: vdev pointer
 * @cm_conn_rsp: Connect response
 *
 * Return: None
 */
void mlme_cm_update_conn_id_and_src(struct wlan_objmgr_vdev *vdev,
				    enum wlan_cm_source source,
				    uint64_t cm_id);

/**
 * mlme_cm_disconnect_complete() - Disconnect response
 * @vdev: vdev pointer
 * @cm_conn_rsp: Connect response
 *
 * Return: None
 */
void mlme_cm_disconnect_complete(struct wlan_objmgr_vdev *vdev,
				 struct wlan_cm_discon_rsp *cm_disconn_rsp);

/**
 * mlme_cm_disconnect_start() - Disconnect start
 * @vdev: vdev pointer
 * @cm_conn_rsp: Connect response
 *
 * Return: None
 */
void mlme_cm_disconnect_start(struct wlan_objmgr_vdev *vdev);

/**
 * typedef osif_cm_get_global_ops_cb() - Callback to get connection manager
 * global ops
 */
typedef struct mlme_cm_ops *(*osif_cm_get_global_ops_cb)(void);

/**
 * mlme_set_osif_cm_cb() - Sets ops registration callback
 * @cm_osif_ops:  Function pointer
 *
 * API to set ops registration call back
 *
 * Return: void
 */
void mlme_set_osif_cm_cb(osif_cm_get_global_ops_cb cm_osif_ops);

#endif

#endif
