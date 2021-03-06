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

#include "C793_WriteUTCTime.h"

uint8_t Compose_C793_WriteUTCTime_Req ( C793_WriteUTCTime_Req* request,
                                    ComposerContext* context,
                                    BinaryStream* toStream )
{
  context->cmdId = CMDID_C793_WriteUTCTime;
  STREAM_WRITE_DATE(toStream, request->m_dDate);
  STREAM_WRITE_TIME(toStream, request->m_tTime);

  return RCS_N00_Success; // success
}

uint8_t Parse_C793_WriteUTCTime_Req ( C793_WriteUTCTime_Req* request,
                                    ParserContext* context,
		                    BinaryStream* fromStream )
{
#if defined(_DEBUG)
//   if (fromStream->remainingBytes > C793_ReqSize)
//     return RCS_E01_Undefined1; // too many bytes
#endif

  STREAM_READ_DATE(fromStream, &request->m_dDate);
  STREAM_READ_TIME(fromStream, &request->m_tTime);

  return RCS_N00_Success; // success
}

uint8_t Compose_C793_WriteUTCTime_Resp ( C793_WriteUTCTime_Resp* response,
                                    ComposerContext* context,
                                    BinaryStream* toStream )
{
  context->cmdId = CMDID_C793_WriteUTCTime;
  STREAM_WRITE_DATE(toStream, response->m_dDate);
  STREAM_WRITE_TIME(toStream, response->m_tTime);

  return RCS_N00_Success; // success
}

uint8_t Parse_C793_WriteUTCTime_Resp ( C793_WriteUTCTime_Resp* response,
                                    ParserContext* context,
		                    BinaryStream* fromStream )
{
#if defined(_DEBUG)
//   if (fromStream->remainingBytes > C793_RespSize)
//     return RCS_E01_Undefined1; // too many bytes
#endif

  STREAM_READ_DATE(fromStream, &response->m_dDate);
  STREAM_READ_TIME(fromStream, &response->m_tTime);

  return RCS_N00_Success; // success
}
