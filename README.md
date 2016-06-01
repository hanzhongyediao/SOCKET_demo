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
        HTTP请求报文： 由请求行，请求头部，空行，请求数据 四部分组成
        请求方法|空格|URL|空格|协议版本|回车|换行
        头部字段名：值|回车|换行
        。。。
        头部字段名：值|回车|换行
        回车|换行
        请求数据
        
#请求方法主要采用 get port
#例如：
  请求报文  
    GET /*.html HTTP/1.1\r\n
    Accept:
    Accept-Language:
    Accept-Encoding:
    User-Agent:
    Host:
    Connection:
    \r\n
    #请求数据
 回显报文
    HTTP/1.1 200
    Date:
    Server:
    Set-cookie:
    Vary:
    Content-Length:
    Connection:
    Content-Type:
    Binary-Data:
    
    class Http_Requst{
        private:
            string request_func
            string URL
            string request_version
            string hostname;
            char* R_Http_Packet;
            vecter <string> header;
        public:
            Http_Requst()
            ~Http_Requst()
            fill_http_head(requstfunc, Url, requestversion, header)
            fill_http_packet(char * data)
            send_requst(int sockfd){
                ssize_t sendfd;
                sendfd = send(sockfd, R_Http_Packet, strlen(R_Http_Packet), 0);
                if(sendfd == -1)
                    
            }
    };
    class Http_Response{
        private:
            string Packet_protocol
            string Response_type
            string Content_type
            unsigned int Content_length
            
            char *G_Http_Packet
        public:
            Http_Response()
            ~Http_Response()
            //每个值都有自己的获取函数
            read_Response(int sockfd){
                ssize_t recvfd;
                recvfd = recv(sockfd, G_Http_Packet, strlen(G_Http_Packet), 0);
                if(recvfd == -1){
                    
                }else if(recvfd == 0){
                    
                }else{
                    success
                }
            }
            get_head_value();
            delete_head();
            get_Content();
    };
    class Url_Download{
        private:
            class Http_Requst 
            class Http_Response
            Url
            HostName
            IpAddr
            port
            int confd
        public:
            Url_Download(_Url)
            SetHostIpAddr();
            SetPort();
            Set_HostName();
            SetClientFd(){
                int sockfd;
                struct sockaddr_in client;
                sockfd = socket(AF_INET,SOCK_STREAM,0);
                assert(sockfd != -1);
                client.sin_addr.s_addr = IpAddr;
                client.sin_port = port;
                client.sin_family = AF_INET;
                confd = connect(sockfd, (struct sockaddr*)&client, sizeof(struct sockaddr_in));
                assert(confd != -1);
            }
            Download(){
                
            }
    }