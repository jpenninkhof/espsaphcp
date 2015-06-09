#include "osapi.h"
#include "user_interface.h"
#include "espconn.h"
#include "mem.h"
#include "saphcp.h"
#include "json/json.h"

// Debug output.
#if 0
#define PRINTF(...) os_printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif

void ICACHE_FLASH_ATTR hcp_send(
		const char * account, const char * landscapehost,
		const char * deviceid, const char * token, const char * data,
		http_callback user_callback)
{

	static char url[256];
	static char headers[128];

	os_sprintf(url,
			"https://iotmms%s.%s/com.sap.iotservices.mms/v1/api/http/data/%s",
			account,
			landscapehost,
			deviceid);
	os_sprintf(headers,
			"Content-Type: %s\r\n"
			"Authorization: Bearer %s\r\n",
			JSON_CONTENT_TYPE, token);

	PRINTF("Request url: %s\r\n", url);
	PRINTF("Request data: %s\r\n", data);
	PRINTF("Headers: %s\r\n", headers);

	http_post(url, data, headers, user_callback);

}
