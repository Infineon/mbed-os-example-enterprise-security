/*
 * Copyright 2019, Cypress Semiconductor Corporation or a subsidiary of
 * Cypress Semiconductor Corporation. All Rights Reserved.
 *
 * This software, including source code, documentation and related
 * materials ("Software"), is owned by Cypress Semiconductor Corporation
 * or one of its subsidiaries ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products. Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 */

#include "mbed.h"
#include "cy_supplicant_core_constants.h"
#include "cy_enterprise_security_interface.h"
#include "certificate.h"

#define APPLICATION_INFO(x) printf x

#define ENT_IDENTITY        "UserIdentity"              /* user name */
#define ENT_PASSWORD        "UserPassword"              /* password */
#define ENT_SSID            "SSID"                      /* SSID of 802.1x enabled WiFi network */
#define ENT_EAP_TYPE        CY_SUPPLICANT_EAP_TYPE_TLS  /* other supported values CY_SUPPLICANT_EAP_TYPE_PEAP CY_SUPPLICANT_EAP_TYPE_TTLS */

NetworkInterface *network;
static EnterpriseSecurity ent;

enterprise_security_parameters_t parameters;

int main()
{
    cy_supplicant_status_t result;
    network = network->get_default_instance();
    int count = 10;

    if ( ( strlen((char *)WIFI_USER_PRIVATE_KEY_STRING) | strlen((char *)WIFI_USER_CERTIFICATE_STRING) | strlen((char *)WIFI_ROOT_CERTIFICATE_STRING) ) < 64 )
    {
        APPLICATION_INFO(("Configure with valid WIFI_USER_PRIVATE_KEY_STRING, WIFI_USER_CERTIFICATE_STRING and WIFI_ROOT_CERTIFICATE_STRING in certificate.h file \n"));
        return -1;
    }

    parameters.ca_cert = (char*) WIFI_ROOT_CERTIFICATE_STRING;
    parameters.client_cert = (char*) WIFI_USER_CERTIFICATE_STRING;
    parameters.client_key = (char*) WIFI_USER_PRIVATE_KEY_STRING;
    memcpy( parameters.ssid, (char *)ENT_SSID, strlen(ENT_SSID) + 1);

    memcpy( parameters.outer_eap_identity, (char *)ENT_IDENTITY, strlen(ENT_IDENTITY) + 1);

    parameters.eap_type = ENT_EAP_TYPE;
    parameters.auth_type = WHD_SECURITY_WPA2_MIXED_ENT;

    if( ENT_EAP_TYPE == CY_SUPPLICANT_EAP_TYPE_PEAP || ENT_EAP_TYPE == CY_SUPPLICANT_EAP_TYPE_TTLS)
    {
        memcpy( parameters.phase2.inner_identity, (char *)ENT_IDENTITY, strlen(ENT_IDENTITY) + 1);
        memcpy( parameters.phase2.inner_password, (char *)ENT_PASSWORD, strlen(ENT_PASSWORD) + 1);

        parameters.phase2.inner_eap_type = CY_SUPPLICANT_EAP_TYPE_MSCHAPV2;
        parameters.phase2.tunnel_auth_type = CY_SUPPLICANT_TUNNEL_TYPE_MSCHAPV2;

        if( ENT_EAP_TYPE == CY_SUPPLICANT_EAP_TYPE_TTLS )
        {
            parameters.phase2.tunnel_auth_type = CY_SUPPLICANT_TUNNEL_TYPE_EAP;
        }
    }

    result = ent.join(&parameters);

    if( result == CY_SUPPLICANT_STATUS_JOIN_SUCCESS )
    {
        APPLICATION_INFO(("Enterprise Security Join successful\n"));
        APPLICATION_INFO(("IP address %s\n", ent.get_ip_address()));
    }
    else
    {
        APPLICATION_INFO(("Enterprise Security Join failed with error %d\n", result));
        return CY_SUPPLICANT_STATUS_JOIN_FAILURE;
    }

    APPLICATION_INFO(("Wait for 15 seconds (To test basic ping from any other peer)\n"));
    while( count-- )
    {
        wait_ms(1500);
    }

    result = ent.leave();

    if( result == CY_SUPPLICANT_STATUS_LEAVE_SUCCESS )
    {
        APPLICATION_INFO(("Enterprise Security Leave successful\n"));
    }
    else
    {
        APPLICATION_INFO(("Enterprise Security Join failed with error %d\n", result));
        return CY_SUPPLICANT_STATUS_LEAVE_FAILURE;
    }
    return CY_SUPPLICANT_STATUS_LEAVE_SUCCESS;

}
