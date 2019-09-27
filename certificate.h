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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/* These are invalid certificates and should only be used to refer the certificate format. Please load valid certificate and private key issued by backend server */

/* Sample Root CA certificate */
/*
#define WIFI_ROOT_CERTIFICATE_STRING  \
"-----BEGIN CERTIFICATE-----\r\n"\
"MIIE5DCCA8ygAwIBAgIJAJbDyfg+a+gzMA0GCSqGSIb3DQEBCwUAMIGTMQswCQYD\r\n"\
"VQQGEwJGUjEPMA0GA1UECAwGUmFkaXVzMRIwEAYDVQQHDAlTb21ld2hlcmUxFTAT\r\n"\
"BgNVBAoMDEV4YW1wbGUgSW5jLjEgMB4GCSqGSIb3DQEJARYRYWRtaW5AZXhhbXBs\r\n"\
"ZS5vcmcxJjAkBgNVBAMMHUV4YW1wbGUgQ2VydGlmaWNhdGUgQXV0aG9yaXR5MB4X\r\n"\
"DTE5MDUyNzA2MDI0M1oXDTM1MTAzMDA2MDI0M1owgZMxCzAJBgNVBAYTAkZSMQ8w\r\n"\
"DQYDVQQIDAZSYWRpdXMxEjAQBgNVBAcMCVNvbWV3aGVyZTEVMBMGA1UECgwMRXhh\r\n"\
"bXBsZSBJbmMuMSAwHgYJKoZIhvcNAQkBFhFhZG1pbkBleGFtcGxlLm9yZzEmMCQG\r\n"\
"A1UEAwwdRXhhbXBsZSBDZXJ0aWZpY2F0ZSBBdXRob3JpdHkwggEiMA0GCSqGSIb3\r\n"\
"DQEBAQUAA4IBDwAwggEKAoIBAQDDrK+KCeXisMB3xULhzaXQftVvC7siyTlk9VJG\r\n"\
"slgbYlyeIoCj1FC87VzgUnVvFTFVqB6gU81nM6UxQ42NXtdS18nnf0+NhE2x3bUR\r\n"\
"w0ktwjXl5dCaTmRr+f5ccFVb5Ec5j+gOQMODCcxBX4RFhj1FxSORV8v8VawdNyXD\r\n"\
"zxj0wAXuLyzU2hnk7DiWYUMCTwReVna9ve7v3PCKV51L+qfOuotG1vLyp3L/Ckoq\r\n"\
"cI27/QdZQvOei+LAmoslhyTzGiEPe06M5ThBIQ9zHWms0gtHI7hAS5qA9heNxe8G\r\n"\
"HBkw+c3Ba8kwmk9nPwpxf4ka7C3vHNOv/9wCGpzM6mr/8YxHAgMBAAGjggE3MIIB\r\n"\
"MzAdBgNVHQ4EFgQUGltUuj0fYK3XeBX4/hD9qRpMk6cwgcgGA1UdIwSBwDCBvYAU\r\n"\
"GltUuj0fYK3XeBX4/hD9qRpMk6ehgZmkgZYwgZMxCzAJBgNVBAYTAkZSMQ8wDQYD\r\n"\
"VQQIDAZSYWRpdXMxEjAQBgNVBAcMCVNvbWV3aGVyZTEVMBMGA1UECgwMRXhhbXBs\r\n"\
"ZSBJbmMuMSAwHgYJKoZIhvcNAQkBFhFhZG1pbkBleGFtcGxlLm9yZzEmMCQGA1UE\r\n"\
"AwwdRXhhbXBsZSBDZXJ0aWZpY2F0ZSBBdXRob3JpdHmCCQCWw8n4PmvoMzAPBgNV\r\n"\
"HRMBAf8EBTADAQH/MDYGA1UdHwQvMC0wK6ApoCeGJWh0dHA6Ly93d3cuZXhhbXBs\r\n"\
"ZS5vcmcvZXhhbXBsZV9jYS5jcmwwDQYJKoZIhvcNAQELBQADggEBAJXXGX/XS3nN\r\n"\
"wQuhzvHIXssiJSA1wDNzSSetuG5Xtq4Gx0DCiy0wNy6Z0cnnjFufArnf8TRT21Tn\r\n"\
"M4MNPZMlMla+TDTiX0dnI6vcFtbplGNohFCI6FFEjveE6qFy3Tv2rMN7w6XrAZqT\r\n"\
"dc/jfE8IljzX30voVsSPAT59g80Fdxu76KEe0arUtJufNJl9lFUlsbDe+Xs9fQVT\r\n"\
"fc0CAll12Co6JqUoNMibEx33e2DJARCXyCQLAkts3YbrASn8XpQumSHHSQfSG5Ks\r\n"\
"r4GI4ltf0E1gBjFNLou7TGjvPNWNrw4fe4Bf0mX3ACVvamIuQShBQryK+rFBjlIA\r\n"\
"qIugahbAcuE=\r\n"\
"-----END CERTIFICATE-----\r\n"\
"\0"\
"\0"
*/
#define WIFI_ROOT_CERTIFICATE_STRING ""

/* Sample Client Private key */
/*
#define WIFI_USER_PRIVATE_KEY_STRING  \
"-----BEGIN RSA PRIVATE KEY-----\r\n"\
"MIIEpQIBAAKCAQEAubbrwVowUmRwreuSwaSvR1Rt0JOcILN4MJmhbx7NHoLKlUg0\r\n"\
"/bjduzFn0MVHFcLVy7s8E6NOAu7T/qcuiewuU69x2LW3mpNbvGfNfWIgIQKes49K\r\n"\
"HNd+gHCCOmGX9aAxHWf6hLv+Ho3V+5oWLzYOeSmbWA/LTTuzBquVWS6zhnxOKv5A\r\n"\
"CQ9O1RCVA6SURno/Lx/96rdEJt32538Xu/4tBypWcaUHFvj+eQNTJQlyKpsOwJIH\r\n"\
"Y7GTQ5zlF25XSGXBkuIBfvEyUcmdGHPTFYSVUuWqmViy+Ov5YFE2tuPtKt3IdqvV\r\n"\
"DaBQcrDkQSqZ4XdktaP4JX7wMYgkOFfRXXQEmQIDAQABAoIBABH0XVaUIZfVng8y\r\n"\
"dz3BbjC3OOaxXqbKsxP/xlu33pzUiEFmebkN5mHypNbKO9UewQyxTV2YrDIcZOJ5\r\n"\
"x0YOT2xHyfnpl5aaKIROhM9abUDDwBQcBk5DhzdjqTN7u/VDR3xQUSgEBM1vaQCq\r\n"\
"JPrrfvq3ywz4ee89llFOxWGZ4kFeGQADkHN+3eDkGQL5u1tgPPYSxSg9LKxR0Ltk\r\n"\
"QCjQ6/g8chnmg0Hd9MIxKEq282F5Qra/Jz2pYy4bwXFhgFIKyqtWSaceK4bG8OZZ\r\n"\
"12WsSjy9fN7q8w+896FXSB36Ol1T/ArRfqfcWqgc/eBIF4E7mBa8CvkyL4kS6MKJ\r\n"\
"nNuMuwECgYEA4kROBflr73sxf956QWHfH0mifNwIihNNrA6wsxcfSbo1gxONxIRH\r\n"\
"OOS2r8ct949+eBSIjlL3bE0VMp3KOh+DLT7/NjDPwke84Mfma7oVYUCWK3EwTmKL\r\n"\
"cD9vTxpI3bxGofcvyL9Iu32brVnSwvMQQrhq5ChJ3FIRGMYoHgLF8psCgYEA0h5s\r\n"\
"VEfofRklJarfZroeBSLqTYq1o7aIp2d5PVQE1gBVYK/YBXd+bvJxtaJpxzHfptVV\r\n"\
"1kjxttJe/O8tvfx5/CkuOpoY7UDmSLT3g9I8IuYJ78l1PgOg4mivGS1RrDe1J9bb\r\n"\
"V5B7rqKsPsV8X5riOxtwmuN2qgtTakGbCcWbDtsCgYEAjkVUqf0DGTnlDfnd9W6M\r\n"\
"1Sd/u/K+i9NHa4BxKqrHSZyEOT76TS6/ec6V8EDVbmwToX2Hv7X7TWXKhmEg3xsh\r\n"\
"aDnMT06x0/83jD8la2c+OkBaLEankSH1e0bnvl1Qo9vWrdC3gwqDuSBp2r43/8zF\r\n"\
"1K4QyBVtG9OeXG18nCIyRTECgYEAwxDvbQcc9RZlACU0JUBgIlCZyMcffg81qoRL\r\n"\
"b/4SR0IkARD+sYSP4hw+KGvRW9YXVeD0QW2SyTFgcdzyUFCWRt1MR6dLwObhY1pt\r\n"\
"9vk0TwnU68HRkHL553dcJzmFeyZ0jbnQA+jkieoHknbw0ikOIeWFkqXdQlwlYp3p\r\n"\
"exbyrsUCgYEAtPWmK4ybbaOxa4YKDiXgNu0M0S7GF5YXkhB3Frur62+bmM3q61C2\r\n"\
"dQ9RmIpLp2VD55QJjh5zeCAFkwc8KGOXItLZ75XrvTgzqx75paBByS706/MqE7Hi\r\n"\
"yD/Y+71joZN0Rk9dfENhxxRbvqqBr9CP2WSMFywbcXZi9t2DyNbdQxM=\r\n"\
"-----END RSA PRIVATE KEY-----\r\n"\
"\0"\
"\0"
*/
#define WIFI_USER_PRIVATE_KEY_STRING  ""

/* Sample Client certificate */
/*
#define WIFI_USER_CERTIFICATE_STRING  (const uint8_t*)\
"-----BEGIN CERTIFICATE-----\r\n"\
"MIIDzzCCAregAwIBAgIBATANBgkqhkiG9w0BAQsFADCBkzELMAkGA1UEBhMCRlIx\r\n"\
"DzANBgNVBAgMBlJhZGl1czESMBAGA1UEBwwJU29tZXdoZXJlMRUwEwYDVQQKDAxF\r\n"\
"eGFtcGxlIEluYy4xIDAeBgkqhkiG9w0BCQEWEWFkbWluQGV4YW1wbGUub3JnMSYw\r\n"\
"JAYDVQQDDB1FeGFtcGxlIENlcnRpZmljYXRlIEF1dGhvcml0eTAeFw0xOTA1Mjcw\r\n"\
"NjAyNTBaFw0xOTA3MjYwNjAyNTBaMHExCzAJBgNVBAYTAkZSMQ8wDQYDVQQIDAZS\r\n"\
"YWRpdXMxFTATBgNVBAoMDEV4YW1wbGUgSW5jLjEZMBcGA1UEAwwQdXNlckBleGFt\r\n"\
"cGxlLm9yZzEfMB0GCSqGSIb3DQEJARYQdXNlckBleGFtcGxlLm9yZzCCASIwDQYJ\r\n"\
"KoZIhvcNAQEBBQADggEPADCCAQoCggEBALm268FaMFJkcK3rksGkr0dUbdCTnCCz\r\n"\
"eDCZoW8ezR6CypVINP243bsxZ9DFRxXC1cu7PBOjTgLu0/6nLonsLlOvcdi1t5qT\r\n"\
"W7xnzX1iICECnrOPShzXfoBwgjphl/WgMR1n+oS7/h6N1fuaFi82Dnkpm1gPy007\r\n"\
"swarlVkus4Z8Tir+QAkPTtUQlQOklEZ6Py8f/eq3RCbd9ud/F7v+LQcqVnGlBxb4\r\n"\
"/nkDUyUJciqbDsCSB2Oxk0Oc5RduV0hlwZLiAX7xMlHJnRhz0xWElVLlqplYsvjr\r\n"\
"+WBRNrbj7SrdyHar1Q2gUHKw5EEqmeF3ZLWj+CV+8DGIJDhX0V10BJkCAwEAAaNP\r\n"\
"ME0wEwYDVR0lBAwwCgYIKwYBBQUHAwIwNgYDVR0fBC8wLTAroCmgJ4YlaHR0cDov\r\n"\
"L3d3dy5leGFtcGxlLmNvbS9leGFtcGxlX2NhLmNybDANBgkqhkiG9w0BAQsFAAOC\r\n"\
"AQEAs7QVOIh8QM6BmOk/asexzhzIX7TaVFxvRscNxEESB7YRykLaskZ49Vd19hAK\r\n"\
"se5Ng2FyXUFjkhODrYBXy+iWysBsay5cDxMTYOaD2zdMB4EzyH3xU6k1osOJLD97\r\n"\
"jVkM5hfPABNGRPF70bx9uYxrXNWUGCIHvHJbXGEb8PiwUhRvYpBrmz+fYqZhVStW\r\n"\
"g868HiykNkHpYg1buyxymJcw/QTi63F99JFYB0B4p2NnHIQh49KZc0yPQKbwKT2L\r\n"\
"KOh0jEUdeem+JHVN2+K8cnSgchBTTJBTSjNPvPWZkwQwGVtzi7sybYV/k88TDrpd\r\n"\
"ZGgPloyLCh+Bb/nl+GEZz6kJaQ==\r\n"\
"-----END CERTIFICATE-----\r\n"\
"\0"\
"\0"
*/
#define WIFI_USER_CERTIFICATE_STRING ""

#ifdef __cplusplus
} /*extern "C" */
#endif
