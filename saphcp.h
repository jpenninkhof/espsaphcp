#ifndef SAPHCP_H
#define SAPHCP_H

/*
 * "full_response" is a string containing all response headers and the response body.
 * "response_body and "http_status" are extracted from "full_response" for convenience.
 *
 * A successful request corresponds to an HTTP status code of 200 (OK).
 * More info at http://en.wikipedia.org/wiki/List_of_HTTP_status_codes
 */
typedef void (* http_callback)(char * response_body, int http_status, char * full_response);

void ICACHE_FLASH_ATTR hcp_makedata(char * data, int msg_type, const char * var, ...);

/*
 * Send data to the SAP HANA Cloud Platform
 * The data should be a JSON String.
 * E.g.:
 * {"mode":"sync", "messageType":"1","messages":[{"Humidity": %s, "Temperature": %s}]}
 */
void ICACHE_FLASH_ATTR hcp_send(
		const char * account, const char * landscapehost,
		const char * deviceid, const char * token, const char * post_data,
		http_callback user_callback);

#endif
