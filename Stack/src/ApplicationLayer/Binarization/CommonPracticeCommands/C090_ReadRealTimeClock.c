/*
* Copyright (C) 2013 Nivis LLC.
* Email:   opensource@nivis.com
* Website: http://www.nivis.com
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, version 3 of the License.
* 
* Redistribution and use in source and binary forms must retain this
* copyright notice.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#include "C090_ReadRealTimeClock.h"

uint8_t Compose_C090_ReadRealTimeClock_Req(C090_ReadRealTimeClock_Req* request, ComposerContext* context,
		BinaryStream* toStream)
{
	context->cmdId = CMDID_C090_ReadRealTimeClock;

	return RCS_N00_Success;
}

uint8_t Parse_C090_ReadRealTimeClock_Req(C090_ReadRealTimeClock_Req* request, ParserContext* context,
		BinaryStream* fromStream)
{
	return RCS_N00_Success;
}

uint8_t Compose_C090_ReadRealTimeClock_Resp(C090_ReadRealTimeClock_Resp* response, ComposerContext* context,
		BinaryStream* toStream)
{
	context->cmdId = CMDID_C090_ReadRealTimeClock;

	STREAM_WRITE_DATE(toStream, response->currentDate);
	STREAM_WRITE_TIME(toStream, response->currentTime);
	STREAM_WRITE_DATE(toStream, response->lastDateSet);
	STREAM_WRITE_TIME(toStream, response->lastTimeSet);
	STREAM_WRITE_UINT8(toStream, response->rtcFlags);

	return RCS_N00_Success;
}

uint8_t Parse_C090_ReadRealTimeClock_Resp(C090_ReadRealTimeClock_Resp* response, ParserContext* context,
		BinaryStream* fromStream)
{
	STREAM_READ_DATE(fromStream, &response->currentDate);
	STREAM_READ_TIME(fromStream, &response->currentTime);
	STREAM_READ_DATE(fromStream, &response->lastDateSet);
	STREAM_READ_TIME(fromStream, &response->lastTimeSet);
	STREAM_READ_UINT8(fromStream, &response->rtcFlags);

	return RCS_N00_Success;
}
