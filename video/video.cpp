
int main(int argc, char *argv[])
{
	
	char path[1024] = "test1.mp4";
	if (MyFFmpeg::Get()->Open(path)) {
		printf("文件[%s]打开成功", path);
	}
	else
	{
		printf("\n文件[%s]打开失败；错误信息：%s", path, MyFFmpeg::Get()->GetError().c_str());
		getchar();
		return -1;
	}

	QApplication a(argc, argv);
	MyPlayer w;
	w.show();
	return a.exec();
}
