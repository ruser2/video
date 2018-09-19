#include "MyFFmpeg.h"
#pragma comment(lib,"avformat.lib")
#pragma comment(lib,"avutil.lib")
#pragma comment(lib,"avcodec.lib")
#pragma comment(lib,"swscale.lib")
bool MyFFmpeg::Open(const char *path) {
	Close();
	mutex.lock();
	int re = avformat_open_input(&ac, path, 0, 0);
	if (re != 0) {//���ļ�ʧ��
		mutex.unlock();
		av_strerror(re, errorbuf, sizeof(errorbuf));
		return false;
	}
	//�õ���Ƶ��ʱ���ĺ�����
	totalMs = ((ac->duration / AV_TIME_BASE) * 1000);
	mutex.unlock();
	return true;
}
void MyFFmpeg::Close() {
	mutex.lock();
	if (ac) avformat_close_input(&ac);
	mutex.unlock();
}
std::string MyFFmpeg::GetError() {
	mutex.lock();
	std::string re = this->errorbuf;
	mutex.unlock();
	return re;
}

MyFFmpeg::MyFFmpeg()
{
	errorbuf[0] = '\0';
	av_register_all();
}
