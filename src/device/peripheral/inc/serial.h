#ifndef _SERIAL_H_
#define _SERIAL_H_

#include "device.h"


/*
 * アシンクロナス・シリアル・インタフェース（ UARTD）
 */
#define UARTChannelNum				UINT_C(8)
#define UARTnCH1					UINT_C(0)
#define UARTnCH2					UINT_C(1)
#define UARTnCH3					UINT_C(2)
#define UARTnCH4					UINT_C(3)
#define UARTnCH5					UINT_C(4)
#define UARTnCH6					UINT_C(5)
#define UARTnCH7					UINT_C(6)
#define UARTnCH8					UINT_C(7)
/*
 *	UARTのベースアドレス
 */
#define UART1_BASE      0xE8007000
#define UART2_BASE      0xE8007800
#define UART3_BASE      0xE8008000
#define UART4_BASE      0xE8008800
#define UART5_BASE      0xE8009000
#define UART6_BASE      0xE8009800
#define UART7_BASE      0xE800A000
#define UART8_BASE      0xE800A800

#define SCFSR_PER_MASK  0xF000          /* パリティエラー数抽出マスク */
#define SCFSR_PER_SHIFT 12              /* パリティエラー数抽出右シフト数 */
#define SCFSR_FER_MASK  0x0F00          /* フレーミングエラー数抽出マスク */
#define SCFSR_FER_SHIFT 8               /* フレーミングエラー数抽出右シフト数 */
#define SCFSR_ER        0x0080          /* 1:受信エラー */
#define SCFSR_TEND      0x0040          /* 1:送信完了 */
#define SCFSR_TDFE      0x0020          /* 1:送信FIFOデータエンプティ */
#define SCFSR_BRK       0x0010          /* 1:ブレーク検出 */
#define SCFSR_FER       0x0008          /* 1:フレーミングエラー検出 */
#define SCFSR_PER       0x0004          /* 1:パリティエラー検出 */
#define SCFSR_RDF       0x0002          /* 1:受信FIFOデータフル */
#define SCFSR_DR        0x0001          /* 1:受信データレディ */


/*
 * 各レジスタのオフセット
 */
#define REG_SCSMR       0x00    /* シリアルモードレジスタ, 16bit */
#define REG_SCBRR       0x04    /* ビットレートレジスタ, 8bit */
#define REG_SCSCR       0x08    /* シリアルコントロールレジスタ, 16bit */
#define REG_SCFTDR      0x0C    /* 送信FIFOデータレジスタ, 8bit */
#define REG_SCFSR       0x10    /* シリアルステータスレジスタ, 16bit */
#define REG_SCFRDR      0x14    /* 受信FIFOデータレジスタ, 8bit */
#define REG_SCFCR       0x18    /* FIFOコントロールレジスタ, 16bit */
#define REG_SCFDR       0x1C    /* FIFOデータカウントレジスタ, 16bit */
#define REG_SCSPTR      0x20    /* シリアルポートレジスタ, 16bit */
#define REG_SCLSR       0x24    /* ラインステータスレジスタ, 16bit */
#define REG_SCEMR       0x28    /* シリアル拡張モードレジスタ, 16bit */


#endif /* _SERIAL_H_ */
