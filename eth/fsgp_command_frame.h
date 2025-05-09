#ifndef USER_PROTOCOL_FSGP_COMMAND_FRAME_H_
#define USER_PROTOCOL_FSGP_COMMAND_FRAME_H_

#include <stdint.h>
#include "frame_defines.h"

#define FSGP_COMM_FRAME_SIZE (FSGP_COMM_FRAME_CTRL_SIZE128+FSGP_COMM_FRAME_SYNC_SIZE128+FSGP_COMM_FRAME_AUX_DATA_SIZE128+FSGP_COMM_FRAME_SIGNAL_SIZE128)*4*4

#define FSGP_BUFFER_SIZE_LW_POS 48*WORD32_BYTE_SIZE + LOW_WORD_OFFSET //115
#define FSGP_QUEUE_SIZE_LW_POS 49*WORD32_BYTE_SIZE + LOW_WORD_OFFSET //123

// Fields value COMM
#define FSGP_COMM_FRAME_CTRL_OFFSET128 3
#define FSGP_COMM_FRAME_CTRL_SIZE128 4

#define FSGP_COMM_FRAME_SYNC_OFFSET128 7
#define FSGP_COMM_FRAME_SYNC_SIZE128 4

#define FSGP_COMM_FRAME_AUX_DATA_OFFSET128 11
#define FSGP_COMM_FRAME_AUX_DATA_SIZE128 0

#define FSGP_COMM_FRAME_SIGNAL_OFFSET128 11
#define FSGP_COMM_FRAME_SIGNAL_SIZE128 0

// Fields value ACK
#define FSGP_ACKFRAME_CTRL_OFFSET128 3
#define FSGP_ACKFRAME_CTRL_SIZE128 2

#define FSGP_ACKFRAME_SYNC_OFFSET128 5
#define FSGP_ACKFRAME_SYNC_SIZE128 1

#define FSGP_ACKFRAME_AUX_DATA_OFFSET128 6
#define FSGP_ACKFRAME_AUX_DATA_SIZE128 0

#define FSGP_ACKFRAME_SIGNAL_OFFSET128 6
#define FSGP_ACKFRAME_SIGNAL_SIZE128 0

/* legacy
typedef struct
{
    // word 12, [31:24], offset 0x6a
   uint8_t reserved1  :6;
   uint8_t SBR_OCH    :1;     //§³§¢§² §°§¹
   uint8_t REG        :1;     //§²§¦§¤

   // word 12, [23:16], offset 0x6b
   uint8_t NKCH       :8;     //§¯§¬§¹

   // word 12, [15:8]
   uint8_t NPO        :4;     //§¯§±§°
   uint8_t reserved2  :4;

   // word 12, [7:0]
   uint8_t KP         :8;     // §¬§à§Õ §á§Ñ§é§Ü§Ú

   // word 13, [31:24]
   uint8_t reserved3  :8;

   // word 13, [23:16]
   uint8_t ZI         :4;     //§©§ª
   uint8_t reserved4  :4;

   // word 13, [15:8]
   uint8_t reserved5  :8;

   // word 13, [7:0]
   uint8_t PS         :1;     //§±§³
   uint8_t CDO        :1;     //§¸§¥§°
   uint8_t PBL        :1;     //§±§¢§­
   uint8_t PF         :1;     //§±§¶
   uint8_t AKP        :1;     //§¡§¬§±
   uint8_t EKV        :1;     //§¿§¬§£
   uint8_t reserved6  :2;

   //word 14, [32:0]
   uint32_t index; // §ª§ß§Õ§Ö§Ü§ã

   //word 15, [32:0]
   uint32_t TVRS;  // §´§Ó§â§ã

   //word 16, [32:0]
   uint32_t reserved7;

   //word 17, [32:0]
   uint32_t reserved8;

   //word 18
   uint8_t reserved9  :8;
   uint8_t reserved10     :8;
   uint8_t reserved11     :8;
   uint8_t OSL_PS     :8;     // §°§ã§Ý.§±§ã

   //word 19, [32:0]
   uint32_t reserved12;

   //word 20, [32:0]
   uint32_t reserved13;

   //word 21, [32:0]
   uint32_t timestamp_hw;

   //word 22, [32:0]
   uint32_t timestamp_mw;

   //word 23, [32:0]
   uint32_t timestamp_lw;
}FSGP_Command_Frame;
*/

typedef struct
{
    // word 16, [31:24], offset 0x6a
    uint8_t RVCH         :2;       //???
    uint8_t reserved1    :3;
    uint8_t PTVRS        :1;     // ?????
    uint8_t SBR_OCH      :1;     //??? ??
    uint8_t REG          :1;     //???

    // word 16, [23:16], offset 0x6b
    uint8_t NKCH         :8;     //???

    // word 16, [15:8]
    uint8_t NPO          :4;     //???
    uint8_t NVt          :1;     //???
    uint8_t reserved2    :3;

    // word 16, [7:0]
    uint8_t KP           :8;     // ?? - ??? ?????

    // word 17, [31:24]
    uint8_t MAKC         :8;     //????

    // word 17, [23:16]
    uint8_t IZL          :1;     //???
    uint8_t SZIZL        :1;     //????
    uint8_t FZI          :1;     //???
    uint8_t reserved3    :1;
    uint8_t ComPCH       :1;     //??? ??
    uint8_t PRKF         :1;     //????
    uint8_t ComPS        :1;     //??? ??
    uint8_t reserved4    :1;

    // word 17, [15:8]
    uint8_t MO           :1;     //??
    uint8_t PG           :1;     //??
    uint8_t CHPK         :1;     //???
    uint8_t reserved5    :5;

    // word 17, [7:0]
    uint8_t PS           :1;     //??
    uint8_t CDO          :1;     //???
    uint8_t PBL          :1;     //???
    uint8_t PF           :1;     //??
    uint8_t AKP          :1;     //???
    uint8_t EKV          :1;     //???
    uint8_t NLCHM        :1;     //????
    uint8_t ADAP         :1;     //????

    //word 18, [31:24]
    uint8_t reserved7;

    //word 18, [23:16]
    uint8_t reserved8;

    //word 18, [15:8]
    uint8_t reserved9;

    //word 18, [7:0]
    uint8_t ImAz         :1; //????
    uint8_t VRASH        :1; //????
    uint8_t SkVRASH      :3; //??????
    uint8_t reserved10   :3;

    //word 19, [31:0]
    uint32_t DVRS;  //???????????? ???

    //word 20, [31:16]
    uint16_t DalnostPS;  //????????? ??

    //word 20, [16:8]
    uint8_t OslableniePS;  //?????????? ??

    //word 20, [7:0]
    uint8_t TipPS        :3; //?????????? ??
    uint8_t PolosaPS     :3; //?????? ??
    uint8_t PnfPS        :1; //??? ??
    uint8_t reserved11   :1;

    //word 21, [31:24]
    uint8_t reserved12;

    //word 21, [23:16]
    uint8_t reserved13   :4;
    uint8_t PNF_ZI       :1; //??? ??
    uint8_t PolosaZI     :3; //?????? ??

    //word 21, [15:0]
    uint16_t SkorostPS;  //???????? ??

    //word 22 [32:0]
    uint8_t KFprdK1  :8;
    uint8_t KFprdK2  :8;
    uint8_t KFprdK3  :8;
    uint8_t KFprdK4  :8;

    //word 23, [32:0]
    uint16_t Xpl;
    uint16_t KPK;

    //word 24... word 31
    uint16_t X[16];  //X1-X16

    //word 32, [32:0]
    uint32_t index;

    //word 33, [32:0]
    uint32_t TVRS;  //????

    //word 34, [32:0]
    uint16_t TNSO;  //??????? ????? ????? ? ??????
    uint16_t TNO;  //??????? ????? ??????

    //word 35, [32:0]
    uint32_t azimutUPR;

    //word 36, [32:0]
    uint32_t azimutSDna4;

    //word 37, [32:0]
    uint32_t azimutSDkon;

    //word 38, [32:0]
    uint32_t Tev63_32;

    //word 39, [32:0]
    uint32_t Tev31_0;

    //word 40, [32:0]
    uint32_t TNS;

    //word 41, [32:0]
    uint32_t timestamp_hw;

    //word 42, [32:0]
    uint32_t timestamp_mw;

    //word 43, [32:0]
    uint32_t timestamp_lw;

    //word 44-47
    uint32_t reservedEnd[4];
}FSGP_Command_Frame;

typedef union
{
   FSGP_Command_Frame structData;
   uint8_t rawData[FSGP_COMM_FRAME_SIZE];
}FSGP_Command_Frame_union;

#endif /* USER_PROTOCOL_FSGP_COMMAND_FRAME_H_ */
