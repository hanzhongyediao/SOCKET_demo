/***********url download module head*************************/
/*     writer : tom-z          */
/*class Http_Requst  is to sending http requst to web server*/
/*class Http_Response is to recving http response for web server*/
/*class Url_Download is core */
/************************************************************/
  
  #ifndef Url_Download_H_
  #define Url_Download_H_
  
  
  #include <iostream>
  #include <string>
  #include <string.h>
  #include <vecter>
  #include <errno.h>
  #include <assert>
  #include "Erorr.h"
  using namespace std;
  
  #undef R_Http_Packet_len 
  #define R_Http_Packet_len 1024
  
  
  class Http_Requst{
        private:
            string requst_func;     //requst function ,for example: GET PORT ... 
            string URL;             //requst resources ,for example: /index.html 
            string requst_version;  //requst version ,for example: HTTP/1.1
            string hostname;        //requst hostname ,for exmple: www.baidu.com
            //hostend可识别的主机名后缀
            vector <string> header; //requst header ,for exmple: Accept:txt/html\r\n
            char* R_Http_Packet;    
        public:
            Http_Requst();
            ~Http_Requst();
            bool get_head_massage(string requstfunc,string Url);
            void add_header(string _header);
            void fill_http_head();
            void fill_http_packet(char * data);
            int send_requst(int sockfd);
    };
    
    class Http_Response{
        private:
            string Packet_protocol;         //packet protocol ,for example: 1xx, 2xx, 3xx, 4xx , 5xx
            string Response_type;           //accept encoding ,for example: gzip deflate sdch
            string Content_type;            //accept content type, forexample: text/html
            unsigned int Content_length;    //accept content length
            
            char *G_Http_Packet;
            unsigned int Packet_len;             
        public:
            Http_Response();
            ~Http_Response();
            read_Response(int sockfd);
            //每个值都有自己的获取函数
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
    };
#endif