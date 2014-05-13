#ifndef ZSY_TYPES_H
#define ZSY_TYPES_H

//#define d_printf(format, ...)	printf(format, __VA_ARGS__)
//#define d_printf(...)	do {printf("%s %d: ", __func__, __LINE__); printf(__VA_ARGS__);}while(0)
#define d_printf(fmt, ...)	do {printf("[%s %d]: " fmt, __func__, __LINE__, ##__VA_ARGS__);\
	}while(0)

#endif
