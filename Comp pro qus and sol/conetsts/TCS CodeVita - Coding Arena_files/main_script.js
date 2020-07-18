//icons (Ashik A)
window.minusIcon = '<svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24"><path stroke="#333" stroke-width="3" d="M12 12h8"/><path stroke="#333" stroke-width="3" d="M12 12h-8"/><path class="plus" stroke="#333" stroke-width="3" d="M12 12v8"/><path class="plus" stroke="#333" stroke-width="3" d="M12 12v-8"/></svg>';
if(window.sessionStorage.getItem('checkpoint') == undefined) window.sessionStorage.setItem('checkpoint','0');


window.history.forward();
function noBack() {
	window.history.forward();
}

/**
* Function to Initialize Tabs (Questions)
* Author : Ashik A
*/
function initializeTabs(){
	var tabSelectors = $('.tab-selectors .tab-selector');
	$('.tab-selectors').css('grid-template-columns','repeat('+tabSelectors.length+',1fr)');

	var pointer_container = $('<div class="tab-selector-pointer"></div>');
	var pointer = $('<div class="pointer"></div>');
	pointer_container.html(pointer);
	var width = 100/tabSelectors.length;
	pointer.css('width',width + '%');
	$(pointer_container).insertAfter('.tab-selectors');

	var tabs = $('.tabs .tab');
	for(var i=0;i<tabs.length;i++){
		$(tabs[i]).css('opacity','0');
		$(tabs[i]).css('display','none');
	}
	$(tabs[0]).css('display','block');
	$(tabs[0]).addClass('active');
	$(tabs[0]).css('opacity','1');

	/*
	* To select the current problem into view
	*/
	tabSelectors.click(function(){
		var id = $(this).html();
		window.sessionStorage.setItem('visited_question',id);
		var TempInterval = setInterval(()=>{
			if($('#file-upload-section h2 .question-character-span').length > 0){
				clearInterval(TempInterval);
				$('.question-character-span').html(id.trim());
			}
		},100);
		var all_tabs = $('.tab-selectors .tab-selector');
		for(var i=0;i<all_tabs.length;i++){
			$(all_tabs[i]).removeClass('active');
		}
		$(this).addClass('active');
		var index = 0;
		for(var i=0;i<all_tabs.length;i++){
			if($(all_tabs[i]).hasClass('active')){
				var absoluteBeginning = index * (100/all_tabs.length);
				pointer.css('left',absoluteBeginning + '%');
				for(var i=0;i<tabs.length;i++){
					$(tabs[i]).css('opacity','0');
					$(tabs[i]).css('display','none');
					$(tabs[i]).removeClass('active');
				}
				$(tabs[index]).css('display','block');
				$(tabs[index]).addClass('active');
				checkIfOnlineEditorAvailable(id);
				setTimeout(()=>{
					$(tabs[index]).css('opacity','1');
				},10);
				break;
			}
			index++;
		}
	});
}

/*
* Function to Detect the Question content and Format them for conditional viewing
* Author : Ashik A
*/
function enhanceContent(){
	var currentQuestion = $('.question_container.active');
	var theMainHeadings = $(currentQuestion).children('h3');
	console.log(theMainHeadings);
	if($(theMainHeadings[0]).hasClass('heading-tab')){
		return;
	}
	var theFinalContent = [];
	for(var i=0;i<theMainHeadings.length;i++) {
		var content = $(theMainHeadings[i]).nextUntil('h3');
		theFinalContent.push(content);
		$(theMainHeadings[i]).remove();
		$(content).remove();
	}

	for(var i=0;i<theMainHeadings.length;i++) {
		var improvedHeading = $('<div></div>').addClass('heading-tab active');
		improvedHeading.html(window.minusIcon);
		improvedHeading.append(theMainHeadings[i]);
		var improvedContent = $('<div class="content-tab"></div>');
		improvedContent.css('opacity','1');
		improvedContent.html(theFinalContent[i]);
		currentQuestion.append(improvedHeading);
		currentQuestion.append(improvedContent);
	}

	$(theMainHeadings).click(function(){
		$(this).parent().toggleClass('active');
		var content = $(this).parent().next('.content-tab');
		var sign = $(this).parent().find('svg path.plus');

		if($(this).parent().hasClass('active')){
			$(sign).attr('class','plus')
			content.css('display','block');
			setTimeout( ()=>{content.css('opacity','1');} , 10);
		}
		else{
			$(sign).attr('class','plus active');
			$(sign).removeClass('active');
			content.css('opacity','0');
			setTimeout( ()=>{content.css('display','none');}, 300); 
		}
	});

}

/*
* Function ViewProblem() : To view the Full Problem Text
* Author : Ashik A
*/
function ViewProblem(object){
	var div = $(object).closest('.question_container');
	$.ajax({
		url: './StartProblem',
		type: 'post',
		data: {
			radio: $(div).attr('id')
		},
		success: function(data){
			$('#main-content').html(data);
			setTimeout(function(){
				$('.question_selector#'+$(div).attr('id')).click();
			}, 500);
		}
	});
}

/*
* Function to Select a Particular Problem
* Author : Ashik A
*/
function SelectProblem(object){
	var problem = $(object).html();
	$('.question-character-span').html(problem.trim());
	var question_content_list = $('.question_container');
	for(var i=0;i<question_content_list.length;i++){
		$(question_content_list[i]).removeClass('active');
	}
	
	$('.question_container#'+problem.trim()).addClass('active');

	var question_selector_list = $('.question_selectors .question_selector');
	for(var i=0;i<question_selector_list.length;i++){
		$(question_selector_list[i]).removeClass('active');
	}
	$(object).addClass('active');
	enhanceContent();
} 

/*
* Function to Set the Submission Space / Notification Space Depending on the condition
* Author : Ashik A
*/
function setSubmissionPanel(booleanValue, data){
	if(booleanValue){
		$('#file-upload-section').html($('#secondary-space').html());
		/*
		* Self Proclamation based Event handler function
		* Author : Ashik A
		*/
		$('#file-upload-section input.actual_solution_upload_input').val('');
		$('#file-upload-section input.actual_solution_upload_input').attr('disabled','disabled');
		$('#file-upload-section input.actual_solution_upload_input + label').html('Choose a File ...');
		$('#file-upload-section .upload_section #submit_solution').attr('disabled','disabled');

		$('#file-upload-section #self_proclamation').change(function(){
			var fileChooser = $('#file-upload-section input[type="file"].actual_solution_upload_input');
			if($(this).is(':checked')) {
				fileChooser.removeAttr('disabled');
				if($('#file-upload-section input.actual_solution_upload_input').val().length > 0){
					$('#file-upload-section .upload_section #submit_solution').removeAttr('disabled');
					$('.file_upload_container .upload_section .extension_container').removeClass('disabled');
				}
			}
			else {
				fileChooser.attr('disabled','disabled');
				$('#file-upload-section .upload_section #submit_solution').attr('disabled','disabled');
				$('.file_upload_container .upload_section .extension_container').addClass('disabled');
			}
		});

		/*
		* Event Listener for File Upload
		* Author : Ashik A
		*/
		$('.actual_solution_upload_input').change(function(){
			$('.actual_solution_upload_input + label').html($(this).prop('files')[0].name);
			$('.upload_section #submit_solution').removeAttr('disabled');
			$('.file_upload_container .upload_section .extension_container').removeClass('disabled');
		});


		$('#attributions').change(function(){
			if($(this).is(':checked')) {
				$('.attribution_section_container').removeClass('disabled');
				
				//$("#links").tagit();
				//alert($("#links").is(":visible"));
				//$('#links').on('load',function(){$(this).tagit();});
				//$('#links').load(function(){$(this).tagit();})
			}
			else {
				$('.attribution_section_container').addClass('disabled');
			}
		});

		/*
		* Event Listener to populate the correct Language Extensions
		* Author : Ashik A
		*/
		$('.actual_solution_upload_input').change(function(){
			var file_name_split = $(this).prop('files')[0].name.split('.');
			var extension = file_name_split.length > 1 ? file_name_split[file_name_split.length - 1] : '';
			var options = $('.extension_container #extension');
			options.html('');
			if(extension.localeCompare('c') == 0) {
				options.append('<option value="C">C</option>');
			}
			else if(extension.localeCompare('cpp') == 0){
				options.append('<option value="Cpp">CPP</option>');
			}
			else if(extension.localeCompare('java') == 0){
				/*options.append('<option value="Java7">Java 7</option>');*/
				options.append('<option value="Java8">Java 8</option>');
			}
			else if(extension.localeCompare('cs') == 0){
				options.append('<option value="Csharp">C#</option>');
			}
			else if(extension.localeCompare('py') == 0){
				//options.append('<option value="Python2">Python 2</option>');
				options.append('<option value="Python3">Python 3</option>');
			}
			else if(extension.localeCompare('py3') == 0){
				options.append('<option value="Python3">Python 3</option>');
			}
			else if(extension.localeCompare('rb') == 0){
				options.append('<option value="Ruby">Ruby</option>');	
			}
			else if(extension.localeCompare('pl') == 0){
				options.append('<option value="Perl">Perl</option>');
			}
			/*else if(extension.localeCompare('js') == 0){
				options.append('<option value="Javascript">Javascript</option>');
			}*/
			else if(extension.localeCompare('php') == 0){
				options.append('<option value="Php">PHP</option>');
			}
			else if(extension.localeCompare('jl') == 0){
				options.append('<option value="Julia">Julia</option>');
			}
		});
		initializeAttributionsUIOnMainPage();
	}
	else{
		if(data == undefined || data == null){
			setSubmissionPanel(true, null);
		}
		var response = typeof(data) == 'string' ? JSON.parse(data) : data;
		var timeLeft;

		if(window.sessionStorage.getItem('checkpoint') != null){
			var currentTime = new Date();
			var currentTime = currentTime.getTime();
			var futureTime = window.sessionStorage.getItem('checkpoint');
			if(currentTime < futureTime){
				timeLeft = parseInt((futureTime - currentTime) / 1000);
			}	
		}
		else{
			setSubmissionPanel(true, null);
			return;
		}

		$('#file-upload-section').html($('#secondary-notification-space').html());
		$('.submission_notification').removeClass('success error');
		$('.submission_notification').addClass(response.type);
		$('#file-upload-section .submission_notification .info > h2').html(response.msg);
		if(response.type.localeCompare('success') == 0){
			$('#file-upload-section .submission_notification .graphic img').attr('src','./images/svgs/happy.svg');
			$('#file-upload-section .submission_notification .graphic .short-msg').html('Yayy!');
			$('#file-upload-section .submission_notification .actions .other-info').html('<span>You can submit the next solution in </span><span class="time-left"></span>');

			console.log(window.sessionStorage.getItem('checkpoint'));
			
			$('#file-upload-section .submission_notification .actions .other-info .time-left').html(timeLeft + ' Seconds');
			window.time_left_interval_var = setInterval(function(){
				timeLeft--;

				$('#file-upload-section .submission_notification .actions .other-info .time-left').html(timeLeft + ' Seconds');
			}, 1000);
			
		}
		else{
			$('#file-upload-section .submission_notification .graphic img').attr('src','./images/svgs/sad.svg');
			$('#file-upload-section .submission_notification .graphic .short-msg').html('Oh No!');
			$('#file-upload-section .submission_notification .actions .other-info').html('<span> </span><span class="btns"><span class="button_red" onclick="{setSubmissionPanel(true,null);}">Lets Try Again</span></span>');
		}
		if(response.type.localeCompare('success') == 0){
			setTimeout( ()=>{
				clearInterval(window.time_left_interval_var);
				setSubmissionPanel(true,null);
			} , (timeLeft * 1000));
		}
	}
}

/*
* submitSolution() : Function called when submitting the Solution
* Author : Ashik A
*/
function submitSolution(){
	var problem_character = $($('.question_selector.active')[0]).html().trim();
	var extension = $('.extension_container #extension > option:selected').val();
	if(extension == undefined){
		setSubmissionPanel(false,{"msg": "Unknown File Type. Please Check the File that you uploaded. Supported extensions : c, cpp, java, cs, rb, py, php, pl","type" : "error"});
		return;
	}
	var data = new FormData();
	var file_name = $($('.actual_solution_upload_input')[0]).prop('files')[0].name;
	data.append(file_name, $($('.actual_solution_upload_input')[0]).prop('files')[0]);
	data.append('extension',extension);
	data.append('problemID',problem_character);
	var hasAttributions = $('.attribution_section_container').hasClass('disabled') ? false : true;
	data.append('attributions',hasAttributions);
	
	var linksValue = '';
	if(hasAttributions)
	{
		$('span.tagit-label').each(function(){
			linksValue = linksValue + $(this).text() + ',';
		});
		if(linksValue.indexOf(',')>-1)
		{
			linksValue = linksValue.substring(0,(linksValue.length)-1);
		}
	}
	//data.append('links',hasAttributions ? $('.attribution_section_container #links').val() : '');
	data.append('links',hasAttributions ? linksValue : '');
	data.append('comments',hasAttributions ? $('.attribution_section_container #comments').val() : '');
	if(!hasAttributions || linksValue!='')
	{
		$('#file-upload-section .upload_section #submit_solution').attr('disabled','disabled');
		$.ajax({
			url: './subServlet',
			type: 'post',
			method: 'post',
			cache: false,
			contentType: false,
			processData: false,
			data: data,
			success: function(response){
				var resp_json = JSON.parse(response);

				var futureTime = new Date();
				futureTime = futureTime.getTime();
				futureTime += window.timeLeft * 1000;

				window.sessionStorage.setItem('latest_status',response);
				window.sessionStorage.setItem('checkpoint',futureTime);
				window.sessionStorage.setItem('visited_question',problem_character);

				setSubmissionPanel(false,response);
			}
		});
	}
	else
	{
		//alert('Kindly provide valid attributions if you have took help from online sources.');
		setSubmissionPanel(false,{"msg": "Kindly provide valid attributions if you have taken help from online sources.","type" : "error"});
		return;
	}
}

/*
*
*
*/
function checkIfOnlineEditorAvailable(id){
	var onlineEditorButton = $('.module .open-code-editor');
	if($('#'+id.trim()+'.question_container').find('button.view_problem').length > 0){
		onlineEditorButton.css('display','none');
	}
	else{
		onlineEditorButton.css('display','inline-block');
		onlineEditorButton.find('#editor-question').html(id.trim());
	}
}

/*
* Opens the Code Editor
* Author : Ashik A
*/
function openCodeEditor(object){
	var problemID = $(object).find('#editor-question').html().trim();
	//"scrollbars=1,status=1,width=1000,height=665,top=0,left=0,resizable=false,toolbar=no, menubar=no"
	//my_window = window.open("code_editor.jsp?problemid="+problemID, "_blank", "", true);
	my_window = window.open("OpenCodeEditor?problemid="+problemID, "_blank", "", true);
}

function initializeAttributionsUIOnMainPage()
{
	var pattern = new RegExp('^(https?:\\/\\/)?'+ // protocol
			//'((([a-z\\d]([a-z\\d-]*[a-z\\d])*)\\.)+[a-z]{2,}|'+ // domain name
			'((([a-z\\d]([a-z\\d-]*[a-z\\d])*)\\.)+[a-z]{2,}|'+ // domain name
			'((\\d{1,3}\\.){3}\\d{1,3}))'+ // OR ip (v4) address
			'(\\:\\d+)?(\\/[-a-z\\d%_.~+]*)*'+ // port and path
			'(\\?[;&a-z\\d%_.~+=-]*)?'+ // query string
			'(\\#[-a-z\\d_]*)?$','i'); // fragment locator
			/*$("#links").on('click', function(){
					  alert($(this).text() + ' has been clicked');
			});*/
    $("#links").tagit({
		afterTagAdded: function addTag (event,ui){
			//alert("HOLA"+ui.tagLabel);
			var urlTest = pattern.test(ui.tagLabel);
			var currTag = ui.tagLabel;
			
		  //alert(urlTest);
		  if(!urlTest)
		  {
			alert('invalid URL:'+currTag);
			$('#links').tagit('removeTagByLabel', currTag);
			//jQuery.Event("keydown", { keyCode: 20 });
		  }
		}
	});
}