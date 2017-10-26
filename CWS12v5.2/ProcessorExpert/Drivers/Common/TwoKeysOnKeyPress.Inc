%- AUTOREGENERATE If you remove this line, this file cannot be rewrited (by default)
%ifndef CommentLine
%{
%endif CommentLine
%;** ===================================================================
%include Common\GeneralEvent.inc (OnKeyPress)
%;**     Description :
%;**         This event is called when some button is pressed or released
%include Common\GeneralParameters.inc (27)
%;**         But1%ParBut1 %>27 - State of the Button 1 - TRUE = pressed
%;**         But2%ParBut2 %>27 - 
%;**         Down%ParDown %>27 - Some key is pressed (TRUE) or released
%;** %>29 (FALSE)
%include Common\GeneralReturnNothing.inc
%;** ===================================================================
%ifndef CommentLine
%}
%endif CommentLine