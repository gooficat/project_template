#include "instr.h"

Opcode opcodes[] = {
	{{0x00, 0}, {{PRM_REG | PRM_MEM, PRM_BYT, FLD_RM}, {PRM_REG, PRM_BYT, FLD_REG}}},
	{{0x01, 0}, {{PRM_REG | PRM_MEM, PRM_WOR, FLD_RM}, {PRM_REG, PRM_WOR, FLD_REG}}},
	{{0x02, 0}, {{PRM_REG, PRM_BYT, FLD_REG}, {PRM_REG | PRM_MEM, PRM_BYT, FLD_RM}}},
	{{0x03, 0}, {{PRM_REG, PRM_WOR, FLD_REG}, {PRM_REG | PRM_MEM, PRM_WOR, FLD_RM}}},

};
