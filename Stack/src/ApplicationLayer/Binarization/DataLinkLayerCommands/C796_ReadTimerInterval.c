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

#include "C796_ReadTimerInterval.h"

uint8_t Compose_C796_ReadTimerInterval_Req ( C796_ReadTimerInterval_Req* request,
                                    ComposerContext* context,
                                    BinaryStream* toStream )
{
  context->cmdId = CMDID_C796_ReadTimerInterval;
  STREAM_WRITE_UINT8(toStream, request->m_ucTimerType);

  return RCS_N00_Success; // success
}

uint8_t Parse_C796_ReadTimerInterval_Req ( C796_ReadTimerInterval_Req* request,
                                    ParserContext* context,
		                    BinaryStream* fromStream )
{
#if defined(_DEBUG)
//   if (fromStream->remainingBytes > C796_ReqSize)
//     return RCS_E01_Undefined1; // too many bytes
#endif

  STREAM_READ_UINT8(fromStream, &request->m_ucTimerType);

  return RCS_N00_Success; // success
}

uint8_t Compose_C796_ReadTimerInterval_Resp ( C796_ReadTimerInterval_Resp* response,
                                    ComposerContext* context,
                                    BinaryStream* toStream )
{
  context->cmdId = CMDID_C796_ReadTimerInterval;
  STREAM_WRITE_UINT8(toStream, response->m_ucTimerType);
  STREAM_WRITE_UINT32(toStream, response->m_ulTimerInterval);

  return RCS_N00_Success; // success
}

uint8_t Parse_C796_ReadTimerInterval_Resp ( C796_ReadTimerInterval_Resp* response,
                                    ParserContext* context,
		                    BinaryStream* fromStream )
{
#if defined(_DEBUG)
//   if (fromStream->remainingBytes > C796_RespSize)
//     return RCS_E01_Undefined1; // too many bytes
#endif

  STREAM_READ_UINT8(fromStream, &response->m_ucTimerType);
  STREAM_READ_UINT32(fromStream, &response->m_ulTimerInterval);

  return RCS_N00_Success; // success
}
