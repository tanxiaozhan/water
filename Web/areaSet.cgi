i header.inc
t <table width="100%" border="0" cellspacing="0" cellpadding="0">
t <tr><td align="center" valign="top">
t <form id="form1" name="form1" method="get" action="content.cgi">
t <table width="800" border="0" cellpadding="0" cellspacing="0">
t <tr><td height="84" colspan="3" align="center" valign="middle"><h3>�֡������衡��</h3></td></tr>
t <tr><td width="359" height="85" align="right" valign="middle"><img src=pabb.gif>�����ţ�</td>
t <td width="180" valign="middle"><input class="tbs" name="areaNo" type="text" id="areaNo" size="10" /></td>
t <td width="261">1-3</td></tr>
t <tr><td height="85" align="right" valign="middle"><img src=pabb.gif>X ���꣺</td>
t <td><input class="tbs" name="X" type="text" id="X" size="10" /></td>
t <td>&nbsp;</td></tr>
t <tr><td height="85" align="right" valign="middle"><img src=pabb.gif>Y ���꣺</td>
t <td><input class="tbs" name="Y" type="text" id="Y" size="10" /></td>
t <td align="left" valign="middle">&nbsp;</td></tr>
t <tr><td height="85" align="right" valign="middle"><img src=pabb.gif>���ȣ�</td>
t <td><input class="tbs" name="Width" type="text" id="Width" size="10" /></td>
t <td align="left" valign="middle">&nbsp;</td></tr>
t <tr><td height="85" align="right" valign="middle"><img src=pabb.gif>�ߡ��ȣ�</td>
t <td><input class="tbs" name="Height" type="text" id="Height" size="10" /></td>
t <td align="left" valign="middle">&nbsp;</td></tr>
t <tr><td height="100" colspan="3" align="center">
t <table width="90%" border="0" cellspacing="0" cellpadding="0">
t <tr><td width="25%" height="30" align="center">&nbsp;</td>
t <td width="30%" height="30" align="center">
t <input type="reset" name="button" value="���塡����" 
t class="tbs" onclick="window.location='areaSet.cgi'" />
t </td><td width="5%" height="30" align="center">&nbsp;</td>
t <td width="27%" height="30" align="center">
t <input type="button" name="button2" value="���ᡡ����" class="tbs" onclick="check();" /></td>
t <td width="13%" height="30" align="center">&nbsp;</td></tr></table></td></tr>
t <tr><td height="50" colspan="3" align="center">&nbsp;</td></tr>
t </table></form></td></tr></table>
t <SCRIPT  LANGUAGE="JavaScript">
t function check(){
t var num;
t var areaFlag = new Array(); 
c a a areaFlag[0]=1;areaFlag[1]=1;areaFlag[2]=1;
t if(document.getElementById("X").value=="" || document.getElementById("Y").value =="" 
t ||document.getElementById("Width").value=="" || document.getElementById("Height").value=="")
t {alert("���벻����!");return;}
t num=parseInt(document.getElementById("areaNo").value); 
t if((num) >3 || (num) < 1){alert("������ֻ����1-3֮���������");
t document.getElementById("areaNo").focus();}
t if( areaFlag[num-1]==1 ){alert("��ʾ����" + num + "�Ѵ��ڣ������ظ�������");return;}
t document.getElementById("form1").submit();}
t </Script>
. End of script must be closed with period.