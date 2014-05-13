#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/videodev2.h>
#include "zsy_types.h"

int main(int argc, char** argv) {
	int ret = 0;
	//打开设备
	int fd = open("/dev/video0", O_RDWR);
	if (fd==-1) {
		perror("open /dev/video error!");
	}
	d_printf("open /dev/video success!\n");
	//设备属性
	struct v4l2_capability cap;
	ret = ioctl(fd, VIDIOC_QUERYCAP, &cap);
	if (ret==-1) {
		perror("VIDIOC_QUERYCAP error!");
		goto END;
	}
	d_printf("driver:%s\n\tcard:%s\n\tbus info:%s\n\tVersion:%u.%u.%u\n\tcap:0x%08x\n",
			cap.driver, cap.card, cap.bus_info, (cap.version>>16)&0xff, 
			(cap.version>>8)&0xff, cap.version&0xff, cap.capabilities);
END:
	//关闭设备
	ret = close(fd);
	if (ret==-1) {
		perror("close fd error!");
	}
	d_printf("close fd:%d success!\n", fd);
	return 0;
}
