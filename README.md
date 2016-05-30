# SOCKET_demo
# 控制模块中的 URL列表 URL列表管理模块 配置文件读取模块 模块管理
# 配置文件设计
    以 键值对的形式：key=value
    注释为#号开头
    内容包括 初始URL InitUrl
            抓取深度 CaptureDepth
            最多同时启动下载任务数量 DownloadNum
            日志文件输出等级 Log_level
            文件存放路径 File_path
            获取的文件类型 File_type
            模块存放路径 Module_path
            模块名称 Module_name
#            class ConfigParser{
                private:    
                    string InitUrl
                    unsigned int CaptureDepth
                    unsigned int DownloadNum
                    char* Log_level
                    const string File_path
                    char** File_type
                    const string Module_path
                    char** Module_name              
                public:
                    ConfigParser();
                    ReadConfigFile();
                    #每一个键值拥有一个获取键值的GetKeyValue()函数
                    GetKeyValue();
 #           };
 
# 下载模块 HTTP头部组装，HTTP头部拆除，页面保存。
#HTTP 头部组装模块设计
        