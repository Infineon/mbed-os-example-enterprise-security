# Introduction
This code example demonstrates how to use Cypress's Cypress's best in class Wi-Fi enabled
PSoC6 devices to connect to enterprise Wi-Fi networks using various Extensible 
Authentication Protocols (EAP) supported by enterprise security middleware library

This application demonstrates connecting to an enterprise network with one of EAP, PEAP or EAP-TTLS

### Supported Platforms
* [PSoC6 WiFi-BT Prototyping Kit (CY8CPROTO-062-4343W)](https://www.cypress.com/documentation/development-kitsboards/psoc-6-wi-fi-bt-prototyping-kit-cy8cproto-062-4343w)
* [PSoC6 WiFi-BT Pioneer Kit (CY8CKIT-062-WiFi-BT)](https://www.cypress.com/documentation/development-kitsboards/psoc-6-wifi-bt-pioneer-kit-cy8ckit-062-wifi-bt)

### Features
* Supports following EAP security protocols: 
    * EAP-TLS
    * PEAPv0 with MSCHAPv2
    * EAP-TTLS with EAP-MSCHAPv2
* Supports TLS session (session ID based) resumption
* Supports 'PEAP Fast reconnect' (this is applicable only for PEAP protocol).
* Supports roaming across APs in the enterprise network (vanilla roaming)
* Supports TLS versions 1.0, 1.1, and 1.2

### RADIUS Servers
This application has been verified with enterprise Wi-Fi networks configured using following RADIUS servers
* IAS 2012
* FreeRadius 3.0.19

### Supported Toolchains
* GCC_ARM
* IAR
* ARMC6

### Dependencies
This section provides the list of dependency libraries required for this 
middleware library to work.
* [ARM mbed-os stack version 5.14 and above](https://os.mbed.com/mbed-os/releases)
* [Cypress Connectivity  Utilities Library](https://github.com/cypresssemiconductorco/connectivity-utilities)
* [Enterprise Security Library](https://github.com/cypresssemiconductorco/enterprise-security)

# Instructions to build enterprise security code example

This section provides the steps to build and download the application on Cypress target platform.
1. Prepare the cloned working directory for mbed
    - *$ mbed config root .*

2. Pull the necessary library dependencies. This will pull mbed-os, CY enterprise security library and its internal 3rd party dependencies (if any)
    - *$ mbed deploy*

3. Configure Root CA certificate, Client certificate, and Client private key in the certificate.h file

4. Configure the following Wi-Fi network credentials to connect to the enterprise network with the desired protocol
    * Set ENT_SSID refers to <SSID> of the 802.1x enabled WiFi network in enterprise_security_app.cpp
        * \#define ENT_SSID < SSID > /* ssid of 802.1x enabled WiFi network */
    * Set ENT_IDENTITY refers to user name in enterprise_security_app.cpp
        * \#define ENT_IDENTITY < username > /* username */
    * Set ENT_PASSWORD refers to password in enterprise_security_app.cpp
        * \#define ENT_PASSWORD < password > /* password */
    * Set ENT_EAP_TYPE refers to one of the following EAP authentication protocol to use in enterprise_security_app.cpp:
        * \#define ENT_EAP_TYPE CY_SUPPLICANT_EAP_TYPE_TLS /* refers to authentication protocol to use eap_tls */
        * \#define ENT_EAP_TYPE CY_SUPPLICANT_EAP_TYPE_PEAP /* refers to authentication protocol to use peapv0-mschapv2 */
        * \#define ENT_EAP_TYPE CY_SUPPLICANT_EAP_TYPE_TTLS /* refers to authentication protocol to use eap_ttls with eap-mschapv2 */

5. Build and download the application on Cypress target platform
    - *$ mbed compile -t GCC_ARM -m CY8CPROTO_062_4343W -f*

6. Reset the board and check serial console logs. Board shall boot and attempt to join the configured enterprise Wi-Fi network.
