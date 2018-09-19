#pragma once
#ifdef __cplusplus
extern "C"
{
#endif
#include <libavutil/avutil.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#ifdef __cplusplus
}
#endif

#include <string>
#include <QMutex>
class MyFFmpeg
{
public:
	/*设置成为单件模式*/
	static MyFFmpeg *Get()
	{
		static MyFFmpeg ff;
		return &ff;
	}

	/**
	 *打开指定路径的视频文件，如果已有打开的视频文件则先关闭
	 */
	bool Open(const char *path);

	//关闭之前打开的视频文件
	void Close();

	//读取视频帧
	AVPacket Read();

	/*获取相关错误信息*/
	std::string GetError();

	/*类析构函数*/
	virtual ~MyFFmpeg();

	/*视频文件总的毫秒数*/
	int totalMs = 0;
protected:
	/*相关错误信息*/
	char errorbuf[1024];

	//应对多线程访问时的同步锁
	QMutex mutex;

	AVFormatContext *ac = NULL;

	/*设置成为单件模式，所以要把构造函数设置为私有*/
	MyFFmpeg();
};

