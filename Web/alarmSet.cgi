i header.inc
t <table width="90%" border="0" cellspacing="0" cellpadding="0">
t <tr><td align="center" valign="top">
t <form id="form1" name="form1" method="get" action="">
t <table width="700" border="0" cellpadding="0" cellspacing="0">
t <tr><td height="84" align="center" valign="middle"><h3>��ʱ����</h3></td></tr>
c s t <tr><td height="85" align="center" valign="middle">ϵͳʱ�䣺%s</td></tr>
t <tr><td height="85" align="center" valign="middle">&nbsp;</td></tr>
t <tr><td height="85" align="center" valign="middle">��ʱʱ��</td></tr>
t <tr><td height="85" align="center" valign="middle">
c s h <input class=tbs name=alarmHour type=text id=hour size=2 value=%d />:    
c s m <input class=tbs name=alarmMin type=text id=minute size=2 value=%d />:
c s s <input class=tbs name=alarmSec type=text id=second size=2 value=%d /></td></tr>
t <tr><td height="85" align="center" valign="middle">��ʱʱ����
c s w <input class=tbs name=water type=text id=waterlast size=2 value=%d />��</td></tr>
t <tr><td height="100" align="center">
t <table width="90%" border="0" cellspacing="0" cellpadding="0">
t <tr><td width="22%" height="30" align="center">&nbsp;</td>
t <td width="28%" height="30" align="center" >
t <button class="tbs" type="button" onclick="window.location='screenSet.html'" >ˢ ��</button></td>
t <td width="10%" height="30" align="center">&nbsp;</td>
t <td width="27%" height="30" align="center" >
t <button class="tbs" type="button" onclick="check();">�� ��</button></td>
t <td width="13%" height="30" align="center">&nbsp;</td></tr></table></td></tr>
t <tr><td height="50" align="center">&nbsp;</td></tr></table></form></td></tr></table>
t <SCRIPT  LANGUAGE="JavaScript">
t function check(){
t var num;
t if(document.getElementById("second").value=="" ||document.getElementById("minute").value=="" 
t || document.getElementById("hour").value==""){alert("���벻����!");return;}
t num=parseInt(document.getElementById("hour").value); 
t if((num) >23 || (num) < 0){alert("Сʱֻ������0-23֮���������");
t document.getElementById("hour").focus();return;}
t num=parseInt(document.getElementById("minute").value); 
t if((num) >59 || (num) < 0){alert("����ֻ������0-59֮���������");
t document.getElementById("minute").focus();return;}
t num=parseInt(document.getElementById("second").value); 
t if((num) >59 || (num) < 0){alert("��ֻ������0-23֮���������");
t document.getElementById("second").focus();return;}
t document.getElementById("result").innerHTML="��ʱ������ɣ�";
t document.getElementById("form1").submit();}
t </Script>
i footer.inc
. End of script must be closed with period