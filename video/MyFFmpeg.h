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
	/*���ó�Ϊ����ģʽ*/
	static MyFFmpeg *Get()
	{
		static MyFFmpeg ff;
		return &ff;
	}

	/**
	 *��ָ��·������Ƶ�ļ���������д򿪵���Ƶ�ļ����ȹر�
	 */
	bool Open(const char *path);

	//�ر�֮ǰ�򿪵���Ƶ�ļ�
	void Close();

	//��ȡ��Ƶ֡
	AVPacket Read();

	/*��ȡ��ش�����Ϣ*/
	std::string GetError();

	/*����������*/
	virtual ~MyFFmpeg();

	/*��Ƶ�ļ��ܵĺ�����*/
	int totalMs = 0;
protected:
	/*��ش�����Ϣ*/
	char errorbuf[1024];

	//Ӧ�Զ��̷߳���ʱ��ͬ����
	QMutex mutex;

	AVFormatContext *ac = NULL;

	/*���ó�Ϊ����ģʽ������Ҫ�ѹ��캯������Ϊ˽��*/
	MyFFmpeg();
};

