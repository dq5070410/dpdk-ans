/*-
 *   BSD LICENSE
 *
 *   Copyright(c) 2010-2014 Netdp Corporation. All rights reserved.
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Netdp Corporation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef __NETDP_SOCKET_INTF_H__
#define __NETDP_SOCKET_INTF_H__

#define NETDP_SOCK_RING_MZ       "SOCK_RING_MZ"


#define NETDP_CTRL_MSG_POOL     "CTRLRING_MSGPOOL"
#define NETDP_CTRL_APP_2_ODP   "CTRLRING_APP2ODP"
#define NETDP_CTRL_ODP_2_APP   "DATASRING_ODP2APP"
#define NETDP_DATA_MSG_POOL    "DATARING_MSG2POOL"
#define NETDP_DATA_APP_2_ODP  "DATARING_APP2ODP"
#define NETDP_DATA_ODP_2_APP  "DATARING_ODP2APP"

#define NETDP_SUPPORT_APP_MAX 32
#define NETDP_NAME_LEN    20

#define NETDP_SOCK_CTRL_MSG_SIZE   128
#define NETDP_SOCK_DATA_MSG_SIZE   64

#define NETDP_SOCK_CTRL_MSG_NUM   64
#define NETDP_SOCK_DATA_MSG_NUM   1024


/**
 *
 *
 */
typedef enum 
{
   NETDP_SOCK_RING_UNUSED,
   NETDP_SOCK_RING_USED,
} netdp_sock_ring_tag_e;

/**
 *
 *
 */
typedef struct 
{
    char app_name[NETDP_NAME_LEN];
    char ctrl_msg_pool[NETDP_NAME_LEN];
    char ctrl_ring_tx[NETDP_NAME_LEN];
    char ctrl_ring_rx[NETDP_NAME_LEN];
    char data_msg_pool[NETDP_NAME_LEN];
    char data_ring_tx[NETDP_NAME_LEN];
    char data_ring_rx[NETDP_NAME_LEN];
    netdp_sock_ring_tag_e ring_tag;
}netdp_sock_ring_conf_t;


/**
 *
 *
 */
 typedef struct 
{
    struct rte_mempool *ctrl_msg_pool;
    struct rte_ring *ctrl_ring_tx;
    struct rte_ring *ctrl_ring_rx;  ;
    struct rte_mempool *data_msg_pool;
    struct rte_ring *data_ring_tx;
    struct rte_ring *data_ring_rx;  ;
}netdp_sock_ring_t;

/**
 *
 *
 */
typedef enum 
{
   NETDP_SOCK_CTRL_CREATE,
   NETDP_SOCK_CTRL_BIND,
   NETDP_SOCK_CTRL_CONNECT,
   NETDP_SOCK_CTRL_CLOSE,
} netdp_sock_ctrl_type_e;





#endif /* __NETDP_SOCKET_INTF_H__ */
