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

#include "C791_AlarmTransportLayerFailed.h"

// Not used - this command shall only be published!
uint8_t Compose_C791_AlarmTransportLayerFailed_Req ( C791_AlarmTransportLayerFailed_Req* request,
                                    ComposerContext* context,
                                    BinaryStream* toStream )
{
  context->cmdId = CMDID_C791_AlarmTransportLayerFailed;

  return RCS_N00_Success; // success
}


uint8_t Parse_C791_AlarmTransportLayerFailed_Req ( C791_AlarmTransportLayerFailed_Req* request,
                                    ParserContext* context,
		                    BinaryStream* fromStream )
{
//#if defined(_DEBUG)
//  if (fromStream->remainingBytes > 0)
//    return RCS_E01_Undefined1; // too many bytes
//#endif

  // This command shall only be published
  // When the field device receives this command it must answer with an "Access Restricted" response code
  return RCS_E16_AccessRestricted;
}


uint8_t Compose_C791_AlarmTransportLayerFailed_Resp ( C791_AlarmTransportLayerFailed_Resp* response,
                                    ComposerContext* context,
                                    BinaryStream* toStream )
{
  context->cmdId = CMDID_C791_AlarmTransportLayerFailed;
  STREAM_WRITE_UINT16(toStream, response->m_unNicknameOfUnreachablePeer);

  return RCS_N00_Success; // success
}


uint8_t Parse_C791_AlarmTransportLayerFailed_Resp ( C791_AlarmTransportLayerFailed_Resp* response,
                                    ParserContext* context,
		                    BinaryStream* fromStream )
{
#if defined(_DEBUG)
//   if (fromStream->remainingBytes > C791_RespSize)
//     return RCS_E01_Undefined1; // too many bytes
#endif

  STREAM_READ_UINT16(fromStream, &response->m_unNicknameOfUnreachablePeer);

  return RCS_N00_Success; // success
}
