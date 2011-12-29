#ifndef EC_INIT_H
#define EC_INIT_H

#include <ec.h>
#include <ec_inet.h>

/* per interface data */
struct iface_env {
   char* name;

   struct ip_addr ip;
   struct ip_addr network;
   struct ip_addr netmask;
   u_int8 mac[MEDIA_ADDR_LEN];

   LIST_HEAD(,net_list) ip6_list;

   int dlt;
   u_int16 mtu;
   u_int8 is_ready   :1;
   u_int8 is_live    :1;
   u_int8 has_ipv4   :1;
   u_int8 has_ipv6   :1;
   u_int8 unoffensive:1;

   void* pcap;          /* pcap_t pointer */
   void* lnet;          /* libnet_t pointer */     
};


EC_API_EXTERN void network_init();
EC_API_EXTERN struct iface_env* iface_by_mac(u_int8 mac[MEDIA_ADDR_LEN]);

#endif
