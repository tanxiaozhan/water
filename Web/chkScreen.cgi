i header.inc
t <table width="100%" border="0" cellspacing="0" cellpadding="0">
t <tr><td align="center" valign="top">
t <form id="form1" name="form1" method="get" action="">
t <table width="800" border="0" cellpadding="0" cellspacing="0">
t <tr><td height="70" align="center" valign="middle"><h3>�� Ļ �� ��</h3></td></tr>
t <tr><td height="15"><input type="hidden" name="chk" id="chk"/></td></tr>
t <tr><td height=100 align=center>
t <button type=button class=tbs onclick="power1('ALLON');" style="background:#FF0"> ����ȫ�� </button>&nbsp;&nbsp;
t <button type=button class=tbs onclick="power1('RED');" style="background:#F00"> ��ɫȫ�� </button>
t </td></tr><tr><td height="100" align="center">
t <button type="button" class="tbs" onclick="power1('GREEN');" style="background:#0F0"> ��ɫȫ�� </button>&nbsp;&nbsp;
t <button type="button" class="tbs" onclick="power1('ALLOFF');">����ȫ��</button></td></tr>
t <tr><td height="100" align="center">
t <button type="button" class="tbs" onclick="power1('EXIT');"> �˳���� </button></td></tr>
t <tr><td height="100" align="center">&nbsp;</td></tr></table></form></td></tr></table>
t <SCRIPT LANGUAGE="JavaScript">
t function power1(chkItem){
t document.getElementById("chk").value=chkItem;
t document.getElementById("form1").submit();}
t </Script>
i footer.inc
. End of script must be closed with period