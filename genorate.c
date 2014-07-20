#include "genorate.h"


void genorateRoomStatusSyncService(char* partnerName){
	partnerName[0] = partnerName[0] + 'A' -'a';
	char filename[1024];
	sprintf(filename,"%s%s",partnerName,"RoomStatusSyncServiceImpl.java");
	FILE* fd = fopen(filename,"w");
	if(fd == NULL){
		fprintf(stderr,"create file error!\n");
	}
	partnerName[0] = partnerName[0] + 'a' -'A';
	fprintf(fd,"package com.meituan.service.mobile.hotel.zhilian.%s.service.impl;\n\n",partnerName);
	fprintf(fd,"import com.meituan.service.mobile.hotel.constants.LogConstants;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.enums.ChannelEnum;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.enums.PartnerEnum;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.service.IZhilianPartnerOuterService;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.service.IZhilianPartnerService;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.service.impl.AbstractZhilianPartnerRoomStatusSyncService;\n");
	fprintf(fd,"import org.apache.commons.logging.Log;\n");
	fprintf(fd,"import org.apache.commons.logging.LogFactory;\n");
	fprintf(fd,"import java.util.concurrent.ExecutorService;\n");
	fprintf(fd,"import java.util.concurrent.Executors;\n\n");

	partnerName[0] = partnerName[0] + 'A' -'a';
	fprintf(fd,"public class %sRoomStatusSyncServiceImpl extends AbstractZhilianPartnerRoomStatusSyncService{\n\n",partnerName);
	partnerName[0] = partnerName[0] + 'a' -'A';
	fprintf(fd,"\tprivate final Log logger = LogFactory.getLog(LogConstants.%s_LOG);\n\n",partnerName);
	fprintf(fd,"\tExecutorService executorService = Executors.newFixedThreadPool(8);\n\n");
	fprintf(fd,"\tprivate IZhilianPartnerOuterService %sOuterService;\n\n",partnerName);
	fprintf(fd,"\tprivate IZhilianPartnerService jinjiangService;\n\n");

	fprintf(fd,"\t@Override\n\tprotected ExecutorService getExecutorService() {\n\t\treturn executorService;\n\t}\n\n");
	fprintf(fd,"\t@Override\n\tprotected PartnerEnum getParterner() {\n\t\treturn PartnerEnum.%s;\n\t}\n\n",partnerName);
	fprintf(fd,"\t@Override\n\tprotected Log getLogger() {\n\t\treturn logger;\n\t}\n");
	fprintf(fd,"\t@Override\n\tprotected ChannelEnum getChannelEnum() {\n\t\treturn ChannelEnum.%s;\n\t}\n\n",partnerName);
	fprintf(fd,"\t@Override\n\tprotected IZhilianPartnerOuterService getOuterService() {\n\t\treturn jinjiangOuterService;\n\t}\n\n");
	fprintf(fd,"\t@Override\n\tprotected IZhilianPartnerService getPartnerService() {\n\t\treturn jinjiangService;\n\t}\n\n");
	
	partnerName[0] = partnerName[0] + 'A' -'a';
	fprintf(fd,"\tpublic void set%s",partnerName);
	partnerName[0] = partnerName[0] + 'a' -'A';
	fprintf(fd,"OuterService(IZhilianPartnerOuterService %sOuterService) {\n\t\tthis.%sOuterService = %sOuterService;\n\t}\n\n",partnerName,partnerName,partnerName);

	partnerName[0] = partnerName[0] + 'A' -'a';
	fprintf(fd,"\tpublic void set%s",partnerName);
	partnerName[0] = partnerName[0] + 'a' -'A';
	fprintf(fd,"Service(IZhilianPartnerService %sService) {\n\t\tthis.%sService = %sService;\n\t}\n\n",partnerName,partnerName,partnerName);
	fprintf(fd,"}");

	fclose(fd);
	return;
}

void genorateOuterService(char* partnerName){
	
	partnerName[0] = partnerName[0] + 'A' -'a';
	char filename[1024];
	sprintf(filename,"%s%s",partnerName,"OuterServiceImpl.java");
	FILE* fd = fopen(filename,"w");
	if(fd == NULL){
		fprintf(stderr,"create file error!\n");
	}


	partnerName[0] = partnerName[0] + 'a' -'A';
	fprintf(fd,"package com.meituan.service.mobile.hotel.zhilian.%s.service.impl;\n\n",partnerName);
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.domain.ExtPoiDO;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.domain.ZhilianRoomStatusDO;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.enums.ChannelEnum;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.enums.OrderCheckinStatusEnum;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.enums.PartnerEnum;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.param.ZhilianOrderParam;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.result.ZhilianOrderResult;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.service.IZhilianPartnerOuterService;\n");
	fprintf(fd,"import org.springframework.beans.factory.InitializingBean;\n");
	fprintf(fd,"import java.util.Date;\n");
	fprintf(fd,"import java.util.List;\n");

	partnerName[0] = partnerName[0] + 'A' -'a';
	fprintf(fd,"public class %sOuterServiceImpl implements IZhilianPartnerOuterService,InitializingBean{\n");
	
	fprintf(fd,"\t@Override\n\tpublic List<ExtPoiDO> getPoiFromRemote(PartnerEnum partnerEnum, ChannelEnum channelEnum) {\n\t\treturn null;\n\t}\n\n");
	fprintf(fd,"\t@Override\n\tpublic List<ZhilianRoomStatusDO> getRemoteRoomStatus(ExtPoiDO extPoiDO, Date start, Date end) {\n\t\treturn null;\n\t}\n\n");
	fprintf(fd,"\t@Override\n\tpublic ZhilianOrderResult booking(ZhilianOrderParam param) {\n\t\treturn null;\n\t}\n\n");
	fprintf(fd,"\t@Override\n\tpublic ZhilianOrderResult cancel(ZhilianOrderParam param) {\n\t\treturn null;\n\t}\n\n");
	fprintf(fd,"\t@Override\n\tpublic OrderCheckinStatusEnum getOrderStatus(ZhilianOrderParam param) {\n\t\treturn null;\n\t}\n\n");
	fprintf(fd,"\t@Override\n\tpublic void afterPropertiesSet() throws Exception {\n\t}\n\n");	

	fprintf(fd,"}");
	fclose(fd);
}

void genorateService(char* partnerName){
	
	partnerName[0] = partnerName[0] + 'A' -'a';
	char filename[1024];
	sprintf(filename,"%s%s",partnerName,"ServiceImpl.java");
	FILE* fd = fopen(filename,"w");
	if(fd == NULL){
		fprintf(stderr,"create file error!\n");
	}

	partnerName[0] = partnerName[0] + 'a' -'A';
	fprintf(fd,"package com.meituan.service.mobile.hotel.zhilian.%s.service.impl;\n\n",partnerName);

	fprintf(fd,"import com.meituan.service.mobile.hotel.constants.LogConstants;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.domain.ExtUserInfoDO;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.enums.ChannelEnum;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.enums.PartnerEnum;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.model.OrderModel;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.service.IZhilianPartnerOuterService;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.service.impl.AbstractZhilianPartnerService;\n");
	fprintf(fd,"import org.apache.commons.logging.Log;\n");
	fprintf(fd,"import org.apache.commons.logging.LogFactory;\n");

	partnerName[0] = partnerName[0] + 'A' -'a';
	fprintf(fd,"public class %sServiceImpl implements IZhilianPartnerService{\n\n",partnerName);

	partnerName[0] = partnerName[0] + 'a' -'A';
	fprintf(fd,"\tprivate final Log logger = LogFactory.getLog(LogConstants.%s_LOG);\n\n",partnerName);	

	fprintf(fd,"\tprivate IZhilianPartnerOuterService %sOuterService;\n\n",partnerName);
	fprintf(fd,"\t@Override\n\tprotected Log getLogger() {\n\t\treturn logger;\n\t}\n");
	fprintf(fd,"\t@Override\n\tprotected ChannelEnum getChannelEnum() {\n\t\treturn ChannelEnum.%s;\n\t}\n\n",partnerName);
	fprintf(fd,"\t@Override\n\tprotected String getPriceCheck(OrderModel orderModel) {\n\t\treturn null;\n\t}\n\n");
	fprintf(fd,"\t@Override\n\tprotected ExtUserInfoDO getExtUserInfo(OrderModel orderModel) {\n\t\treturn null;\n\t}\n\n");
	fprintf(fd,"\t@Override\n\tprotected IZhilianPartnerOuterService getOuterService() {\n\t\treturn jinjiangOuterService;\n\t}\n\n");
	partnerName[0] = partnerName[0] + 'A' -'a';
	fprintf(fd,"\tpublic void set%s",partnerName);
	partnerName[0] = partnerName[0] + 'a' -'A';
	fprintf(fd,"OuterService(IZhilianPartnerOuterService %sOuterService) {\n\t\tthis.%sOuterService = %sOuterService;\n\t}\n\n",partnerName,partnerName,partnerName);

	fprintf(fd,"}");
	fclose(fd);
}

