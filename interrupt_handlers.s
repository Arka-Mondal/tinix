# idtload.s : interrupt handlers
# Licensed under GPLv3
# Author    : Arka Mondal
# Copyright (C) 2024  Arka Mondal

.macro interrupt_handler_nc int_no
.global int_handler_\int_no
.type int_handler_\int_no, @function
int_handler_\int_no:
  pushl         $0                  # push 0 as error code
  pushl         \int_no             # push the interrupt number
  jmp           cmn_int_handler     # jump to common interrupt handler
.endm

.macro interrupt_handler int_no
.global int_handler_\int_no
.type int_handler_\int_no, @function
int_handler_\int_no:
  pushl         \int_no             # push the interrupt number
  jmp           cmn_int_handler     # jump to common interrupt handler
.endm

.text
.type cmn_int_handler, @function
cmn_int_handler:
  pusha

  xorl          %eax, %eax
  movw          %ds, %ax
  pushl         %eax

  movw          $0x10, %ax
  movw          %ax, %ds
  movw          %ax, %es
  movw          %ax, %fs
  movw          %ax, %gs

  pushl         %esp
  call          isr_handler
  popl          %esp

  popl          %eax
  movw          %ax, %ds
  movw          %ax, %es
  movw          %ax, %fs
  movw          %ax, %gs

  popa
  addl          $0x8, %esp
  iret

interrupt_handler_nc 0
interrupt_handler_nc 1
interrupt_handler_nc 2
interrupt_handler_nc 3
interrupt_handler_nc 4
interrupt_handler_nc 5
interrupt_handler_nc 6
interrupt_handler_nc 7
interrupt_handler 8
interrupt_handler_nc 9
interrupt_handler 10
interrupt_handler 11
interrupt_handler 12
interrupt_handler 13
interrupt_handler 14
interrupt_handler_nc 15
interrupt_handler_nc 16
interrupt_handler 17
interrupt_handler_nc 18
interrupt_handler_nc 19
interrupt_handler_nc 20
interrupt_handler 21
interrupt_handler_nc 22
interrupt_handler_nc 23
interrupt_handler_nc 24
interrupt_handler_nc 25
interrupt_handler_nc 26
interrupt_handler_nc 27
interrupt_handler_nc 28
interrupt_handler_nc 29
interrupt_handler_nc 30
interrupt_handler_nc 31
interrupt_handler_nc 32
interrupt_handler_nc 33
interrupt_handler_nc 34
interrupt_handler_nc 35
interrupt_handler_nc 36
interrupt_handler_nc 37
interrupt_handler_nc 38
interrupt_handler_nc 39
interrupt_handler_nc 40
interrupt_handler_nc 41
interrupt_handler_nc 42
interrupt_handler_nc 43
interrupt_handler_nc 44
interrupt_handler_nc 45
interrupt_handler_nc 46
interrupt_handler_nc 47
interrupt_handler_nc 48
interrupt_handler_nc 49
interrupt_handler_nc 50
interrupt_handler_nc 51
interrupt_handler_nc 52
interrupt_handler_nc 53
interrupt_handler_nc 54
interrupt_handler_nc 55
interrupt_handler_nc 56
interrupt_handler_nc 57
interrupt_handler_nc 58
interrupt_handler_nc 59
interrupt_handler_nc 60
interrupt_handler_nc 61
interrupt_handler_nc 62
interrupt_handler_nc 63
interrupt_handler_nc 64
interrupt_handler_nc 65
interrupt_handler_nc 66
interrupt_handler_nc 67
interrupt_handler_nc 68
interrupt_handler_nc 69
interrupt_handler_nc 70
interrupt_handler_nc 71
interrupt_handler_nc 72
interrupt_handler_nc 73
interrupt_handler_nc 74
interrupt_handler_nc 75
interrupt_handler_nc 76
interrupt_handler_nc 77
interrupt_handler_nc 78
interrupt_handler_nc 79
interrupt_handler_nc 80
interrupt_handler_nc 81
interrupt_handler_nc 82
interrupt_handler_nc 83
interrupt_handler_nc 84
interrupt_handler_nc 85
interrupt_handler_nc 86
interrupt_handler_nc 87
interrupt_handler_nc 88
interrupt_handler_nc 89
interrupt_handler_nc 90
interrupt_handler_nc 91
interrupt_handler_nc 92
interrupt_handler_nc 93
interrupt_handler_nc 94
interrupt_handler_nc 95
interrupt_handler_nc 96
interrupt_handler_nc 97
interrupt_handler_nc 98
interrupt_handler_nc 99
interrupt_handler_nc 100
interrupt_handler_nc 101
interrupt_handler_nc 102
interrupt_handler_nc 103
interrupt_handler_nc 104
interrupt_handler_nc 105
interrupt_handler_nc 106
interrupt_handler_nc 107
interrupt_handler_nc 108
interrupt_handler_nc 109
interrupt_handler_nc 110
interrupt_handler_nc 111
interrupt_handler_nc 112
interrupt_handler_nc 113
interrupt_handler_nc 114
interrupt_handler_nc 115
interrupt_handler_nc 116
interrupt_handler_nc 117
interrupt_handler_nc 118
interrupt_handler_nc 119
interrupt_handler_nc 120
interrupt_handler_nc 121
interrupt_handler_nc 122
interrupt_handler_nc 123
interrupt_handler_nc 124
interrupt_handler_nc 125
interrupt_handler_nc 126
interrupt_handler_nc 127
interrupt_handler_nc 128
interrupt_handler_nc 129
interrupt_handler_nc 130
interrupt_handler_nc 131
interrupt_handler_nc 132
interrupt_handler_nc 133
interrupt_handler_nc 134
interrupt_handler_nc 135
interrupt_handler_nc 136
interrupt_handler_nc 137
interrupt_handler_nc 138
interrupt_handler_nc 139
interrupt_handler_nc 140
interrupt_handler_nc 141
interrupt_handler_nc 142
interrupt_handler_nc 143
interrupt_handler_nc 144
interrupt_handler_nc 145
interrupt_handler_nc 146
interrupt_handler_nc 147
interrupt_handler_nc 148
interrupt_handler_nc 149
interrupt_handler_nc 150
interrupt_handler_nc 151
interrupt_handler_nc 152
interrupt_handler_nc 153
interrupt_handler_nc 154
interrupt_handler_nc 155
interrupt_handler_nc 156
interrupt_handler_nc 157
interrupt_handler_nc 158
interrupt_handler_nc 159
interrupt_handler_nc 160
interrupt_handler_nc 161
interrupt_handler_nc 162
interrupt_handler_nc 163
interrupt_handler_nc 164
interrupt_handler_nc 165
interrupt_handler_nc 166
interrupt_handler_nc 167
interrupt_handler_nc 168
interrupt_handler_nc 169
interrupt_handler_nc 170
interrupt_handler_nc 171
interrupt_handler_nc 172
interrupt_handler_nc 173
interrupt_handler_nc 174
interrupt_handler_nc 175
interrupt_handler_nc 176
interrupt_handler_nc 177
interrupt_handler_nc 178
interrupt_handler_nc 179
interrupt_handler_nc 180
interrupt_handler_nc 181
interrupt_handler_nc 182
interrupt_handler_nc 183
interrupt_handler_nc 184
interrupt_handler_nc 185
interrupt_handler_nc 186
interrupt_handler_nc 187
interrupt_handler_nc 188
interrupt_handler_nc 189
interrupt_handler_nc 190
interrupt_handler_nc 191
interrupt_handler_nc 192
interrupt_handler_nc 193
interrupt_handler_nc 194
interrupt_handler_nc 195
interrupt_handler_nc 196
interrupt_handler_nc 197
interrupt_handler_nc 198
interrupt_handler_nc 199
interrupt_handler_nc 200
interrupt_handler_nc 201
interrupt_handler_nc 202
interrupt_handler_nc 203
interrupt_handler_nc 204
interrupt_handler_nc 205
interrupt_handler_nc 206
interrupt_handler_nc 207
interrupt_handler_nc 208
interrupt_handler_nc 209
interrupt_handler_nc 210
interrupt_handler_nc 211
interrupt_handler_nc 212
interrupt_handler_nc 213
interrupt_handler_nc 214
interrupt_handler_nc 215
interrupt_handler_nc 216
interrupt_handler_nc 217
interrupt_handler_nc 218
interrupt_handler_nc 219
interrupt_handler_nc 220
interrupt_handler_nc 221
interrupt_handler_nc 222
interrupt_handler_nc 223
interrupt_handler_nc 224
interrupt_handler_nc 225
interrupt_handler_nc 226
interrupt_handler_nc 227
interrupt_handler_nc 228
interrupt_handler_nc 229
interrupt_handler_nc 230
interrupt_handler_nc 231
interrupt_handler_nc 232
interrupt_handler_nc 233
interrupt_handler_nc 234
interrupt_handler_nc 235
interrupt_handler_nc 236
interrupt_handler_nc 237
interrupt_handler_nc 238
interrupt_handler_nc 239
interrupt_handler_nc 240
interrupt_handler_nc 241
interrupt_handler_nc 242
interrupt_handler_nc 243
interrupt_handler_nc 244
interrupt_handler_nc 245
interrupt_handler_nc 246
interrupt_handler_nc 247
interrupt_handler_nc 248
interrupt_handler_nc 249
interrupt_handler_nc 250
interrupt_handler_nc 251
interrupt_handler_nc 252
interrupt_handler_nc 253
interrupt_handler_nc 254
interrupt_handler_nc 255
