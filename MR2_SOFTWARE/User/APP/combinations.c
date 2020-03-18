#include "combinations.h"

//bool optoelec_switch[2];

/**
*��϶��� ��������д��
*�У�		JUMP		��ʼ����		��������		Խ��		�����߼�
*/

void StepOver(void)
{

    state=REALSE;				//�ͷ�
    vTaskDelay(500);

    StepOver_one_leg(0);  //��0
    vTaskDelay(100);

    StepOver_one_leg(1);	//��1
    vTaskDelay(100);



    state=REALSE;				//�ͷ�
    vTaskDelay(150);

//    x = 18*sin(40*PI/180);		//ǰ�����ȱ���һ��СС��վ���� ��һ��
//    y = 18*cos(40*PI/180);
//    CartesianToTheta(1.0);
//    SetCoupledPosition(0);
//    SetCoupledPosition(1);
//    vTaskDelay(100);

    _leg_active[0]=NO;		//�ر�ǰ������
    _leg_active[1]=NO;
    state=TEST4;				//ǰ���������
    vTaskDelay(500);
    _leg_active[0]=YES;		//��ǰ������
    _leg_active[1]=YES;
    vTaskDelay(1500);

    state=TEST6;				//С�鲽
    vTaskDelay(1000);

    state=REALSE; 			//�ͷ�

    // pid_spd_out_limit=  2500;

    StepOver_one_leg(2);	//��2

    vTaskDelay(400);

    StepOver_one_leg(3);	//��3
    vTaskDelay(400);

    // pid_spd_out_limit=  6720;

    state=REALSE;		//�ͷ�
    vTaskDelay(500);

    x = 18.6*sin(28*PI/180);		//�������� Сվ ��ǰ��
    y = 18.6*cos(28*PI/180);
    CartesianToTheta(1.0);
    SetCoupledPosition(2);
    SetCoupledPosition(3);
    vTaskDelay(100);

    _leg_active[2]=NO;		//�رպ�������
    _leg_active[3]=NO;
    state=TEST5; //ǰ������ �����������
    vTaskDelay(500);

    _leg_active[2]=YES;		//�򿪺�������
    _leg_active[3]=YES;
    vTaskDelay(1000);

    state=REALSE;		//�ͷ�
    vTaskDelay(250);

    state=TROT;		    //С������ɳ��

    vTaskDelay(3000);


    // pid_spd_out_limit=  6700;


}


void StepOver_one_leg(int LegId)
{

    //------�ĸ�����ȫ��̧�����-----//

    if(LegId==0||LegId==2)
    {
        x = 0;
        y = 28;
        CartesianToTheta(1.0);
        CommandAllLegs_v();
        vTaskDelay(500);
    }
    else if(LegId==1||LegId==3)
    {
        vTaskDelay(200);
    }

    //--------�Խ��������--------//
    int rev_legid, rev_legid1;
    if(LegId==0) {
        rev_legid=3 ;
        y = 25;
    }
    else if(LegId==1) {
        x = 0;
        y = 28;
        CartesianToTheta(1.0);
        SetCoupledPosition(3);
        vTaskDelay(300);

        rev_legid=2 ;
        y = 25 ;
    }

    else if(LegId==2) {
        rev_legid=1 ;
        y = 25;
    }
    else if(LegId==3) {
        rev_legid=0 ;
        y = 16;
    }
    x = 0;
    CartesianToTheta(1.0);
    SetCoupledPosition(rev_legid);
    vTaskDelay(400);

    //----ֻ��leg3��ʱ������----ǰ�����Ƚ���ƽ��״̬---//

    if(LegId==3)
    {

        if(GROUND_SELECT==RED_GROUNG) {  //�������ж� �쳡

            x = -18*sin(17.2*PI/180);
            y = 18*cos(17.2*PI/180);
            CartesianToTheta(1.0);
            SetCoupledPosition(0);

            x = -21*sin(15*PI/180);
            y = 21*cos(15*PI/180);
            CartesianToTheta(1.0);
            SetCoupledPosition(1);

            x = 22*sin(10*PI/180);
            y = 22*cos(40*PI/180)-4;		//�߶ȱ���
            CartesianToTheta(1.0);
            SetCoupledPosition(2);

            vTaskDelay(1500);
        }
        else if(GROUND_SELECT==BLUE_GROUNG) {

            x = -18*sin(17.2*PI/180);
            y = 18*cos(17.2*PI/180);
            CartesianToTheta(1.0);
            SetCoupledPosition(0);

            x = -21*sin(15*PI/180);
            y = 21*cos(15*PI/180);
            CartesianToTheta(1.0);
            SetCoupledPosition(1);

            x = 22*sin(10*PI/180);
            y = 22*cos(40*PI/180)-4;		//�߶ȱ���
            CartesianToTheta(1.0);
            SetCoupledPosition(2);

            vTaskDelay(1300);
        }

    }

    //--------��������--------//
    if(LegId==3)
    {
        x = -10*sin(80*PI/180);
        y = 10*cos(80*PI/180);
        CartesianToTheta(1.0);
        SetCoupledPosition(LegId);
        vTaskDelay(200);
    }
    else
    {

//        x = -10*sin(60*PI/180);
//        y = 10*cos(60*PI/180);
//        CartesianToTheta(1.0);
//        SetCoupledPosition(LegId);
//        vTaskDelay(600);

    }

    //-------�������ǰ----------//
    x = 10*sin(60*PI/180);
    y = 10*cos(60*PI/180);
    CartesianToTheta(1.0);
    SetCoupledPosition(LegId);
    vTaskDelay(260);

    //--------���״̬��ǰ--------//
    x = 26*sin(80*PI/180);
    y = 26*cos(80*PI/180);
    CartesianToTheta(1.0);
    SetCoupledPosition(LegId);
    vTaskDelay(180);

    //--------���״̬���´���--------//
    if(LegId==0||LegId==1)
    {
        x = 29*sin(34*PI/180);
        y = 29*cos(34*PI/180);
    }
    else if(LegId==2)
    {
        x = 22*sin(40*PI/180);
        y = 22*cos(40*PI/180);
    }
    else if(LegId==3)
    {
        x = 20*sin(50*PI/180);
        y = 20*cos(50*PI/180);
    }
    CartesianToTheta(1.0);
    SetCoupledPosition(LegId);
    vTaskDelay(180);

}



void CrossTheLine(void)
{

    pid_spd_out_limit=  3000;

    state=REALSE;

    CrossTheLine_one_leg(0); //��0
    vTaskDelay(50);

    CrossTheLine_one_leg(1);	//��1
    vTaskDelay(50);

    // now_time=HAL_GetTick();
    LinearCorrection=test1_correction;		//�򿪿�����ʱ��Ĳ�̬��ƫ
    state=TEST1;  //------------��ǰ���ú��ȽӴ�����
    vTaskDelay(1600);
    state=REALSE;

    CrossTheLine_one_leg(2);		//��2
    vTaskDelay(50);

    CrossTheLine_one_leg(3);		//��3
    vTaskDelay(50);

    //**********�м�����**********//
    // now_time=HAL_GetTick();
    state=TEST1;

    vTaskDelay(1600);

    //OpenMvInspect(openmv_Red);  //��⵽��ɫ֮��ʼ���ڶ�������

    IndicateLED_On;

    state=STOP;
    state=REALSE;

    //**********END**********//

    CrossTheLine_one_leg(0);
    vTaskDelay(50);

    IndicateLED_Off;

    CrossTheLine_one_leg(1);
    vTaskDelay(50);

    // now_time=HAL_GetTick();
    state=TEST1;  //�����Ӳ�̬
    vTaskDelay(1600);
    state=REALSE;

    CrossTheLine_one_leg(2);
    vTaskDelay(50);

    CrossTheLine_one_leg(3);
    vTaskDelay(50);



}

void CrossTheLine_one_leg(int LegId)
{

    //------�ĸ�����ȫ��̧�����-----//
    x = 0;
    y = 28;
    CartesianToTheta(1.0);
    CommandAllLegs_v();
    vTaskDelay(150);

    //--------�Խ��������--------//
    int rev_legid;
    if(LegId==0) rev_legid=3;
    else if(LegId==1) rev_legid=2;
    else if(LegId==2) rev_legid=1;
    else if(LegId==3) rev_legid=0;
    x = 0;
    y = 24;
    CartesianToTheta(1.0);
    SetCoupledPosition(rev_legid);
    vTaskDelay(150);

    //��ǰ�������µ�һ�±���ƽ��//
    x = 0;
    y = 29.9;
    CartesianToTheta(1.0);
    SetCoupledPosition(LegId);
    vTaskDelay(800);

    //--------���������--------//
    x = -24*sin(60*PI/180);
    y = 24*cos(60*PI/180);
    CartesianToTheta(1.0);
    SetCoupledPosition(LegId);
    vTaskDelay(140);

    //--------��������ں���--------//
    x = -12*sin(80*PI/180);
    y = 12*cos(80*PI/180);
    CartesianToTheta(1.0);
    SetCoupledPosition(LegId);
    vTaskDelay(220);

    //--------�����״̬��ǰ--------//
    x = 12*sin(60*PI/180);
    y = 12*cos(60*PI/180);
    CartesianToTheta(1.0);
    SetCoupledPosition(LegId);
    vTaskDelay(150);

    //--------���쳤��ǰ--------//
    x = 22*sin(55*PI/180);
    y = 22*cos(55*PI/180);
    CartesianToTheta(1.0);
    SetCoupledPosition(LegId);
    vTaskDelay(140);

    //--------������´���--------//
    x = 29*sin(1*PI/180); //1��
    y = 29*cos(1*PI/180);
    CartesianToTheta(1.0);
    SetCoupledPosition(LegId);
    vTaskDelay(140);

    //------�ĸ��Ȼָ���ʼλ��-----//
    x = 0;
    y = 28;
    CartesianToTheta(1.0);
    CommandAllLegs_v();
    vTaskDelay(100);

}

void OpenMvInspect(int color)
{

    u8 _rel_time = 10;
    u16 time_flag = 0;
    while(1)
    {
        time_flag+=10;

        if(time_flag==10000)
            break;

        vTaskDelay(_rel_time);
        if(openmv2info.ActVal[2]==color)
        {
            vTaskDelay(_rel_time);
            if(openmv2info.ActVal[2]==color)
            {
                vTaskDelay(_rel_time);
                if(openmv2info.ActVal[2]==color)
                {
                    vTaskDelay(_rel_time);
                    if(openmv2info.ActVal[2]==color)
                    {
                        vTaskDelay(_rel_time);
                        if(openmv2info.ActVal[2]==color)
                            break;
                    }
                }

            }
        }
    }

}

float OpenMv_Line_Dec(void)
{

//	float dev_calc_ang;
//
//	dev_calc_ang = pid_calc(&pid_openmv_dev,openmvinfo.ActVal[0],);
//
//
//	return
}

void Climbing_Comb(void)
{

    IndicateLED_On;
    //...����------------
    while(keyInf1!=0) //��һ�����-------�ȴ���翪��--�������³���-----
        vTaskDelay(500);

    IndicateLED_Off;

    LinearCorrection=Deny;

    LinearCorrection=climbing_correction;
    //LinearCorrection=normal_correction;

    yaw_set=imuinfo.ActVal[0];//�趨��ǰ�Ƕ�Ϊǰ������

    // now_time=HAL_GetTick();
    climbing_offset_flag=YES;
    _climbing_offset_angle=15.0;

    state= CLIMBING;



		 while(1)		//ͣ
            vTaskDelay(500);



    vTaskDelay(3000);  //��ʱ3000




    u16 time_flag = 0;

    while(1)
    {
        time_flag+=10;

        if(time_flag==10000)
            break;

        vTaskDelay(10);
        if(openmv2info.ActVal[2]==openmv_Red)
            break;

    }
    //OpenMvInspect(openmv_Red);  //�ȴ���⵽��ɫ ɫ�� ����ͷ�Ѿ���⵽���������¶�




    IndicateLED_On;

    // vTaskDelay(1500);

    IndicateLED_Off;

//    state_detached_params[CLIMBING].detached_params_0.stance_height+=2;
//    state_detached_params[CLIMBING].detached_params_1.stance_height+=2;
//    vTaskDelay(150);

//    state_detached_params[CLIMBING].detached_params_0.stance_height+=2;
//    state_detached_params[CLIMBING].detached_params_1.stance_height+=2;
//    vTaskDelay(150);

//    state_detached_params[CLIMBING].detached_params_0.stance_height+=2;
//    state_detached_params[CLIMBING].detached_params_1.stance_height+=2;
//    vTaskDelay(150);

//    state_detached_params[CLIMBING].detached_params_0.stance_height+=2;
//    state_detached_params[CLIMBING].detached_params_1.stance_height+=2;
//    vTaskDelay(150);

//    state_detached_params[CLIMBING].detached_params_0.stance_height+=2;
//    state_detached_params[CLIMBING].detached_params_1.stance_height+=2;
//    vTaskDelay(150);

    state= REALSE;
    vTaskDelay(300);

    x=0;
    y = 24;
    CartesianToTheta(1.0);
    CommandAllLegs_v();

    vTaskDelay(800);

    CAN_RoboModule_DRV_Position_Mode(0,1,4700,2200*4*15.15);		//����������  2100

vTaskDelay(600);
    x=0;
    y = 26;
    CartesianToTheta(1.0);
    CommandAllLegs_v();
		
		
		vTaskDelay(900);
    x=0;
    y = 26;
    CartesianToTheta(1.0);
    CommandAllLegs_v();
		
		
    state= REALSE;

    vTaskDelay(5000);

    CAN_RoboModule_DRV_Position_Mode(0,1,2500,0);

}

float temp_theta;
u8 start_ready_flag[8] = {0};
void StartPosToMiddlePos (void)
{
    state = REALSE;

    pid_spd_out_limit=600;

    temp_theta=60.0;

    temp_pid.ref_agle[0]+=temp_theta*ReductionAndAngleRatio;
    temp_pid.ref_agle[1]+=temp_theta*ReductionAndAngleRatio;
    temp_pid.ref_agle[2]-=temp_theta*ReductionAndAngleRatio;
    temp_pid.ref_agle[3]-=temp_theta*ReductionAndAngleRatio;

    temp_pid.ref_agle[4]+=temp_theta*ReductionAndAngleRatio;
    temp_pid.ref_agle[5]+=temp_theta*ReductionAndAngleRatio;
    temp_pid.ref_agle[6]-=temp_theta*ReductionAndAngleRatio;
    temp_pid.ref_agle[7]-=temp_theta*ReductionAndAngleRatio;

    IsMotoReadyOrNot= IsReady;		//����������

    vTaskDelay(1500);
//----------------------------���õ�ǰ��Ϊ���--------------------------//
    memset(&moto_chassis,0,sizeof(moto_measure_t)*8);

    for(int i=0; i<8; i++)
        temp_pid.ref_agle[i]=ref_agle[i]=0;

    state = REALSE;

    vTaskDelay(500);
    //----------------------------������--------------------------//
//    x=0;
//    y = 11;
//    CartesianToTheta(1.0);

//    CommandAllLegs_v();

//    vTaskDelay(1000);


    pid_spd_out_limit=  6720;

}

void MiddlePosToEndPos (void)
{

    pid_spd_out_limit=  2500;

    state = REALSE;
    x=0;
    y = 17.3205081;

    CartesianToTheta(1.0);
    CommandAllLegs_v();

    vTaskDelay(1200);

    pid_spd_out_limit=  600;

    temp_theta=-60.0;

    temp_pid.ref_agle[0]+=temp_theta*ReductionAndAngleRatio;
    temp_pid.ref_agle[1]+=temp_theta*ReductionAndAngleRatio;
    temp_pid.ref_agle[2]-=temp_theta*ReductionAndAngleRatio;
    temp_pid.ref_agle[3]-=temp_theta*ReductionAndAngleRatio;

    temp_pid.ref_agle[4]+=temp_theta*ReductionAndAngleRatio;
    temp_pid.ref_agle[5]+=temp_theta*ReductionAndAngleRatio;
    temp_pid.ref_agle[6]-=temp_theta*ReductionAndAngleRatio;
    temp_pid.ref_agle[7]-=temp_theta*ReductionAndAngleRatio;

    IsMotoReadyOrNot= IsReady;		//����������

    vTaskDelay(2000);

    pid_spd_out_limit=  6720;



    state = REALSE;
}