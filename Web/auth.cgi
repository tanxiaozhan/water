i header.inc
t <h3 align=center>�ǡ�¼���衡��</h3>
t <form action="" method=post name=cgi><input type=hidden name=auth id=auth>
t <table width=80% border=0 align="center">
t <tr><td width="45%" align="right"><img src=pabb.gif>�����֤��</TD>
t <td width="55%">
c l 1 <input type=radio name=au  id=authON style=width:40px;height:40px; %s>���á�
c l 2 <input type=radio name=au  id=authOff style=width:40px;height:40px; %s>ͣ��
t </TD></tr>
t <tr><td colspan="2" align="center"></TD></tr>
t </table><p align=center>
t <input type=button name=set value="���ᡡ����" class="tbs" onclick="check(this.form);">&nbsp;&nbsp;&nbsp;
t <input type=button value="�޸�����" class="tbs" onclick="window.location='password.cgi'"></p>
t </form>
t <script language=JavaScript>
t function check(f){
t if(document.getElementById("authON").checked){
t document.getElementById("auth").value="true";}
t else{
t document.getElementById("auth").value="false";}
t document.getElementById("result").innerHTML="��¼������ɣ�";
t f.submit();}
t </script>
i footer.inc
. End of script must be closed with period