#include "Url_Download.h"
//class Http_Requst achieve
Http_Requst::Http_Requst(){
    requst_func = "GET";
    URL = "/";
    request_version = "HTTP/1.1";
    hostname = "www.baidu.com";
    header.clear();
    if(R_Http_Packet != NULL){
        delete [] R_Http_Packet;
    }
    R_Http_Packet = new char[R_Http_Packet_len];
    memset(R_Http_Packet, 0, strlen(R_Http_Packet));
}
Http_Requst::~Http_Requst(){
    if(R_Http_Packet != NULL)
        delete [] R_Http_Packet;
    header.clear();
}
Http_Requst::get_head_massage(string requstfunc, string Url){
    memset(R_Http_Packet, 0, strlen(R_Http_Packet));
    requst_func = requstfunc;
    int find;
    string hostend[] = {"com", "cn", "org"};
    for(int i=0; i<3; i++){ 
        find = Url.rfind( hostend[i] );
        if(find != string::npos){
            string _hostname(Url.begin(), Url.begin() + find + hostend[i].size());
            string _url(Url.begin() + find + hostend[i].size(), Url.end());
            hostname = _hostname;
            URL = url;
            return true;
        }
    }
    return false;
}
void Http_Requst::add_header(string _header){
    header.push_back(_header);
}
void Http_Requst::fill_http_head(){
   string Requst_row;
   string Requst_head;
   //Requst row 
   Requst_row = requst_func + " " + URL + " " + request_version + "\r\n";
   strcat(R_Http_Packet, Requst_row.c_str());
   //Requst head
   for(vector<string>::iterator str = header.begin(); str < header.end(); str++){
         Requst_head += (str+"\r\n"); 
   }
   strcat(R_Http_Packet, Requst_head.c_str());
   //blank line
   strcat(R_Http_Packet, "\r\n");
}
void Http_Requst::fill_http_packet(char *data){
    if(strlen(R_Http_Packet) != 0)
        memset(R_Http_Packet, 0, stlen(R_Http_Packet));
    fill_http_head();
    if(strlen(data) != 0)
        strcat(R_Http_Packet, data);
}
int Http_Requst::send_requst(int sockfd){
    ssize_t sendfd;
    sendfd = send(sockfd, R_Http_Packet, strlen(R_Http_Packet), 0);
    if(sendfd == -1)
        EXIT_MASSAGE("send fail:");
    exit(EXIT_SUCCESS);
}


//class Http_Response
class Http_Response::Http_Response(){
    if(G_Http_Packet != NULL)
        delete [] G_Http_Packet;
    G_Http_Packet = new char[R_Http_Packet_len];
    Packet_len = R_Http_Packet_len;
}
class Http_Response::~Http_Response(){
    if(G_Http_Packet != NULL)
        delete [] G_Http_Packet; 
    Packet_len = 0;
}
class Http_Response::read_Response(int sockfd){
    ssize_t recvfd;
    char *tmp_Packet;
    char *buf = NULL;
    tmp_Packet = new char[R_Http_Packet_len];
    recvfd = recv(sockfd, tmp_Packet, R_Http_Packet_len, 0);
    if(recvfd == -1){
        //日志
        cout<<"errno recv"<<endl;
        return ERROR;
    }else if(recvfd == 0){
        close(sockfd);
        return CLOSE;               
    }else{
        if(Packet_len < (int len1 = strlen(R_Http_Packet)) + (int len2 = strlen(tmp_Packet))){
            buf = new char[len1+len2];
            Packet_len = len1+len2;
            strcpy(buf, R_Http_Packet);
            delete [] R_Http_Packet;
            R_Http_Packet = buf;
            buf = NULL;
        }
        strcat(R_Http_Packet, tmp_Packet);
        cout<<"success"<<endl;
    }
    return SUCCESS;
}
