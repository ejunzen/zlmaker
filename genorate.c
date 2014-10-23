#include "genorate.h"


void genorateRoomStatusSyncService(char* partnerName){
	partnerName[0] = partnerName[0] + 'A' -'a';
	char filename[1024];
	sprintf(filename,"%s%s",partnerName,"RoomStatusSyncServiceImpl.java");
	FILE* fd = fopen(filename,"w");
	if(fd == NULL){
		fprintf(stderr,"create file error!\n");
		return;
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
	fprintf(fd,"\tprivate final static Log logger = LogFactory.getLog(LogConstants.%s_LOG);\n\n",partnerName);
	fprintf(fd,"\tExecutorService executorService = Executors.newFixedThreadPool(8);\n\n");
	fprintf(fd,"\tprivate IZhilianPartnerOuterService %sOuterService;\n\n",partnerName);
	fprintf(fd,"\tprivate IZhilianPartnerService %sService;\n\n",partnerName);

	fprintf(fd,"\t@Override\n\tprotected ExecutorService getExecutorService() {\n\t\treturn executorService;\n\t}\n\n");
	fprintf(fd,"\t@Override\n\tprotected PartnerEnum getParterner() {\n\t\treturn PartnerEnum.%s;\n\t}\n\n",partnerName);
	fprintf(fd,"\t@Override\n\tprotected Log getLogger() {\n\t\treturn logger;\n\t}\n");
	fprintf(fd,"\t@Override\n\tprotected ChannelEnum getChannelEnum() {\n\t\treturn ChannelEnum.%s;\n\t}\n\n",partnerName);
	fprintf(fd,"\t@Override\n\tprotected IZhilianPartnerOuterService getOuterService() {\n\t\treturn %sOuterService;\n\t}\n\n",partnerName);
	fprintf(fd,"\t@Override\n\tprotected IZhilianPartnerService getPartnerService() {\n\t\treturn %sService;\n\t}\n\n",partnerName);

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
		return;
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
	fprintf(fd,"public class %sOuterServiceImpl implements IZhilianPartnerOuterService,InitializingBean{\n",partnerName);

	fprintf(fd,"\t@Override\n\tpublic List<ExtPoiDO> getPoiFromRemote(PartnerEnum partnerEnum, ChannelEnum channelEnum) {\n\t\treturn null;\n\t}\n\n");
	fprintf(fd,"\t@Override\n\tpublic List<ZhilianRoomStatusDO> getRemoteRoomStatus(ExtPoiDO extPoiDO, Date start, Date end) {\n\t\treturn null;\n\t}\n\n");
	fprintf(fd,"\t@Override\n\tpublic ZhilianOrderResult booking(ZhilianOrderParam param) {\n\t\treturn null;\n\t}\n\n");
	fprintf(fd,"\t@Override\n\tpublic ZhilianOrderResult cancel(ZhilianOrderParam param) {\n\t\treturn null;\n\t}\n\n");
	fprintf(fd,"\t@Override\n\tpublic OrderCheckinStatusEnum getOrderStatus(ZhilianOrderParam param) {\n\t\treturn null;\n\t}\n\n");
	fprintf(fd,"\t@Override\n\tpublic void afterPropertiesSet() throws Exception {\n\t}\n\n");	

	fprintf(fd,"}");
	partnerName[0] = partnerName[0] + 'a' -'A';
	fclose(fd);
}

void genorateService(char* partnerName){

	partnerName[0] = partnerName[0] + 'A' -'a';
	char filename[1024];
	sprintf(filename,"%s%s",partnerName,"ServiceImpl.java");
	FILE* fd = fopen(filename,"w");
	if(fd == NULL){
		fprintf(stderr,"create file error!\n");
		return;
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
	fprintf(fd,"public class %sServiceImpl extends AbstractZhilianPartnerService{\n\n",partnerName);

	partnerName[0] = partnerName[0] + 'a' -'A';
	fprintf(fd,"\tprivate final static Log logger = LogFactory.getLog(LogConstants.%s_LOG);\n\n",partnerName);	

	fprintf(fd,"\tprivate IZhilianPartnerOuterService %sOuterService;\n\n",partnerName);
	fprintf(fd,"\t@Override\n\tprotected Log getLogger() {\n\t\treturn logger;\n\t}\n");
	fprintf(fd,"\t@Override\n\tprotected ChannelEnum getChannelEnum() {\n\t\treturn ChannelEnum.%s;\n\t}\n\n",partnerName);
	fprintf(fd,"\t@Override\n\tprotected String getPriceCheck(OrderModel orderModel) {\n\t\treturn null;\n\t}\n\n");
	fprintf(fd,"\t@Override\n\tprotected ExtUserInfoDO getExtUserInfo(OrderModel orderModel) {\n\t\treturn null;\n\t}\n\n");
	fprintf(fd,"\t@Override\n\tprotected IZhilianPartnerOuterService getOuterService() {\n\t\treturn %sOuterService;\n\t}\n\n",partnerName);
	partnerName[0] = partnerName[0] + 'A' -'a';
	fprintf(fd,"\tpublic void set%s",partnerName);
	partnerName[0] = partnerName[0] + 'a' -'A';
	fprintf(fd,"OuterService(IZhilianPartnerOuterService %sOuterService) {\n\t\tthis.%sOuterService = %sOuterService;\n\t}\n\n",partnerName,partnerName,partnerName);

	fprintf(fd,"}");
	fclose(fd);
}

void genorateOrderSyncService(char* partnerName){

	partnerName[0] = partnerName[0] + 'A' -'a';
	char filename[1024];
	sprintf(filename,"%s%s",partnerName,"OrderSyncServiceImpl.java");
	FILE* fd = fopen(filename,"w");
	if(fd == NULL){
		fprintf(stderr,"create file error!\n");
		return;
	}
	partnerName[0] = partnerName[0] + 'a' -'A';
	fprintf(fd,"package com.meituan.service.mobile.hotel.zhilian.%s.service.impl;\n\n",partnerName);
	fprintf(fd,"import com.meituan.service.mobile.hotel.constants.LogConstants;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.enums.ChannelEnum;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.service.IZhilianPartnerOuterService;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.service.IZhilianPartnerService;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.service.impl.AbstractZhilianPartnerOrderSyncService;\n");
	fprintf(fd,"import org.apache.commons.logging.Log;\n");
	fprintf(fd,"import org.apache.commons.logging.LogFactory;\n");

	partnerName[0] = partnerName[0] + 'A' -'a';
	fprintf(fd,"public class %sOrderSyncServiceImpl extends AbstractZhilianPartnerOrderSyncService{\n\n",partnerName);

	partnerName[0] = partnerName[0] + 'a' -'A';
	fprintf(fd,"\tprivate final Log logger = LogFactory.getLog(LogConstants.%s_LOG);\n\n",partnerName);	

	fprintf(fd,"\tprivate IZhilianPartnerOuterService %sOuterService;\n\n",partnerName);
	fprintf(fd,"\tprivate IZhilianPartnerService %sService;\n\n",partnerName);
	fprintf(fd,"\t@Override\n\tprotected Log getLogger() {\n\t\treturn logger;\n\t}\n");
	fprintf(fd,"\t@Override\n\tprotected ChannelEnum getChannelEnum() {\n\t\treturn ChannelEnum.%s;\n\t}\n\n",partnerName);
	fprintf(fd,"\t@Override\n\tprotected IZhilianPartnerOuterService getOuterService() {\n\t\treturn %sOuterService;\n\t}\n\n",partnerName);
	fprintf(fd,"\t@Override\n\tprotected IZhilianPartnerService getPartnerService() {\n\t\treturn %sService;\n\t}\n\n",partnerName);

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
}


void genoratePoiSyncJob(char* partnerName){

	partnerName[0] = partnerName[0] + 'A' -'a';
	char filename[1024];
	sprintf(filename,"%s%s",partnerName,"PoiSyncJob.java");
	FILE* fd = fopen(filename,"w");
	if(fd == NULL){
		fprintf(stderr,"create file error!\n");
		return;
	}

	partnerName[0] = partnerName[0] + 'a' -'A';
	fprintf(fd,"package com.meituan.service.mobile.hotel.zhilian.%s.service.impl;\n\n",partnerName);

	fprintf(fd,"import com.meituan.service.mobile.hotel.constants.LogConstants;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.enums.ChannelEnum;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.enums.PartnerEnum;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.job.AbstractZhilianPartnerPoiSyncJob;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.service.IZhilianPartnerOuterService;\n");
	fprintf(fd,"import com.meituan.service.mobile.hotel.zhilian.service.IZhilianPartnerService;\n");
	fprintf(fd,"import org.apache.commons.logging.Log;\n");
	fprintf(fd,"import org.apache.commons.logging.LogFactory;\n");
	partnerName[0] = partnerName[0] + 'A' -'a';
	fprintf(fd,"public class %sPoiSyncJob extends AbstractZhilianPartnerPoiSyncJob{\n\n",partnerName);

	partnerName[0] = partnerName[0] + 'a' -'A';
	fprintf(fd,"\tprivate final Log logger = LogFactory.getLog(LogConstants.%s_LOG);\n\n",partnerName);	

	fprintf(fd,"\tprivate IZhilianPartnerOuterService %sOuterService;\n\n",partnerName);
	fprintf(fd,"\tprivate IZhilianPartnerService %sService;\n\n",partnerName);
	fprintf(fd,"\t@Override\n\tprotected PartnerEnum getPartnerEnum() {\n\t\treturn PartnerEnum.%s;\n\t}\n\n",partnerName);
	fprintf(fd,"\t@Override\n\tprotected Log getLogger() {\n\t\treturn logger;\n\t}\n");
	fprintf(fd,"\t@Override\n\tprotected ChannelEnum getChannelEnum() {\n\t\treturn ChannelEnum.%s;\n\t}\n\n",partnerName);
	fprintf(fd,"\t@Override\n\tprotected IZhilianPartnerOuterService getPartnerOuterService() {\n\t\treturn %sOuterService;\n\t}\n\n",partnerName);
	fprintf(fd,"\t@Override\n\tprotected IZhilianPartnerService getPartnerService() {\n\t\treturn %sService;\n\t}\n\n",partnerName);

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
}

void genorateServiceXml(char* partnerName){
	
	partnerName[0] = partnerName[0] + 'A' -'a';
	char filename[1024];
	sprintf(filename,"%s%s",partnerName,"-service.xml");
	FILE* fd = fopen(filename,"w");
	if(fd == NULL){
		fprintf(stderr,"create file error!\n");
		return;
	}

	partnerName[0] = partnerName[0] + 'a' -'A';
	fprintf(fd,"<bean id=\"%sOuterService\" class=\"com.meituan.service.mobile.hotel.zhilian.%s.service.impl.",partnerName,partnerName);
	partnerName[0] = partnerName[0] + 'A' -'a';
	fprintf(fd,"%sOuterServiceImpl\"/>\n",partnerName);
	partnerName[0] = partnerName[0] + 'a' -'A';
    fprintf(fd,"<bean id=\"%sService\" class=\"com.meituan.service.mobile.hotel.zhilian.%s.service.impl.",partnerName,partnerName);
	partnerName[0] = partnerName[0] + 'A' -'a';
	fprintf(fd,"%sServiceImpl\"/>\n",partnerName);
	partnerName[0] = partnerName[0] + 'a' -'A';
    fprintf(fd,"<bean id=\"%sRoomStatusSyncService\" class=\"com.meituan.service.mobile.hotel.zhilian.%s.service.impl.",partnerName,partnerName);
	partnerName[0] = partnerName[0] + 'A' -'a';
	fprintf(fd,"%sRoomStatusSyncServiceImpl\"/>\n",partnerName);
	partnerName[0] = partnerName[0] + 'a' -'A';
    fprintf(fd,"<bean id=\"%sOrderService\" class=\"com.meituan.service.mobile.hotel.zhilian.%s.service.impl.",partnerName,partnerName);
	partnerName[0] = partnerName[0] + 'A' -'a';
	fprintf(fd,"%sOrderServiceImpl\"/>\n",partnerName);
	partnerName[0] = partnerName[0] + 'a' -'A';
    fprintf(fd,"<bean id=\"%sOrderSyncService\" class=\"com.meituan.service.mobile.hotel.zhilian.%s.service.impl.",partnerName,partnerName);
	partnerName[0] = partnerName[0] + 'A' -'a';
	fprintf(fd,"%sOrderSyncServiceImpl\"/>\n",partnerName);	
	partnerName[0] = partnerName[0] + 'a' -'A';
	fclose(fd);
}

void genorateTaskXml(char* partnerName){
	
	partnerName[0] = partnerName[0] + 'A' -'a';
	char filename[1024];
	sprintf(filename,"%s%s",partnerName,"-task.xml");
	FILE* fd = fopen(filename,"w");
	if(fd == NULL){
		fprintf(stderr,"create file error!\n");
		return;
	}

	partnerName[0] = partnerName[0] + 'a' -'A';
	fprintf(fd,"\t<bean id=\"%sPoiSyncJob\"\n",partnerName);
    fprintf(fd,"\t\tclass=\"com.meituan.service.mobile.hotel.zhilian.%s.job.",partnerName);
	partnerName[0] = partnerName[0] + 'A' -'a';
	fprintf(fd,"%sPoiSyncJob\">\n",partnerName);
	partnerName[0] = partnerName[0] + 'a' -'A';
    fprintf(fd,"\t\t<property name=\"%sOuterService\" ref=\"%sOuterService\"/>\n",partnerName,partnerName);
    fprintf(fd,"\t\t<property name=\"%sService\" ref=\"%sService\"/>\n",partnerName,partnerName);
    fprintf(fd,"\t</bean>\n\n");

	fprintf(fd,"\t<bean id=\"%sPoiSyncTrigger\" class=\"org.springframework.scheduling.quartz.CronTriggerBean\">\n",partnerName);
    fprintf(fd,"\t\t<property name=\"jobDetail\">\n");
    fprintf(fd,"\t\t<bean class=\"org.springframework.scheduling.quartz.MethodInvokingJobDetailFactoryBean\">\n");
    fprintf(fd,"\t\t\t<property name=\"targetObject\" ref=\"%sPoiSyncJob\"/>\n",partnerName);
    fprintf(fd,"\t\t\t<property name=\"targetMethod\" value=\"syncPerDay\"/>\n");
    fprintf(fd,"\t\t\t<property name=\"concurrent\" value=\"false\"/>\n");
    fprintf(fd,"\t\t</bean>\n");
    fprintf(fd,"\t\t</property>\n");
    fprintf(fd,"\t\t<property name=\"cronExpression\" value=\"0 0 2 * * ?\"/>\n");
    fprintf(fd,"\t</bean>\n");

	
	fprintf(fd,"\t<bean id=\"%sRoomStatusSyncPerHourJobTrigger\" class=\"org.springframework.scheduling.quartz.CronTriggerBean\">\n",partnerName);
    fprintf(fd,"\t\t<property name=\"jobDetail\">\n");
    fprintf(fd,"\t\t<bean class=\"org.springframework.scheduling.quartz.MethodInvokingJobDetailFactoryBean\">\n");
    fprintf(fd,"\t\t\t<property name=\"targetObject\" ref=\"%sRoomStatusSyncService\"/>\n",partnerName);
    fprintf(fd,"\t\t\t<property name=\"targetMethod\" value=\"syncPerHour\"/>\n");
    fprintf(fd,"\t\t\t<property name=\"concurrent\" value=\"false\"/>\n");
    fprintf(fd,"\t\t</bean>\n");
    fprintf(fd,"\t\t</property>\n");
    fprintf(fd,"\t\t<property name=\"cronExpression\" value=\"0 */30 * * * ?\"/>\n");
    fprintf(fd,"\t</bean>\n");

	fprintf(fd,"\t<bean id=\"%sOrderSyncJobTrigger\" class=\"org.springframework.scheduling.quartz.CronTriggerBean\">\n",partnerName);
    fprintf(fd,"\t\t<property name=\"jobDetail\">\n");
    fprintf(fd,"\t\t<bean class=\"org.springframework.scheduling.quartz.MethodInvokingJobDetailFactoryBean\">\n");
    fprintf(fd,"\t\t\t<property name=\"targetObject\" ref=\"%sOrderSyncService\"/>\n",partnerName);
    fprintf(fd,"\t\t\t<property name=\"targetMethod\" value=\"sync\"/>\n");
    fprintf(fd,"\t\t\t<property name=\"concurrent\" value=\"false\"/>\n");
    fprintf(fd,"\t\t</bean>\n");
    fprintf(fd,"\t\t</property>\n");
    fprintf(fd,"\t\t<property name=\"cronExpression\" value=\"0 0 */2 * * ?\"/>\n");
    fprintf(fd,"\t</bean>\n");

	fclose(fd);
}
