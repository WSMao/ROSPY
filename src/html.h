static const char PROGMEM INDEX2_HTML[] = R"rawliteral(
<!doctype html>
<html>
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width,initial-scale=1">
        <title>86Duino feat. ESP32</title>
        <style>
            /* @import "index.css"; */
            html{
                margin:0px;
                width:100%; height:100%;
            }
            body{
                margin:0px;
                width:100%;height:100%;
                background:#718fcc;
                background-image: url("https://idahodarksky.org/wp-content/uploads/2018/04/Milky-Way-SNRA-6-18-17-26710-Nils-Ribi-web-2.jpg");
                background-size: cover;
                background-repeat:no-repeat;
                background-size: 100% 100%;
                color:#000000;
                font-size:16px;
            }

            section.main{
                display:flex;
                flex-direction:column;
            }

            #sidebar{
                position:absolute;
                opacity:0.9;
                z-index: 100;
                width:320px;
                top:50px;
                left:20px;
                /*padding:0px;*/
            }

            #menu{
                display:none;
                flex-direction:column;
                flex-wrap:nowrap;
                background:#666666;
                padding:8px;
                border-radius:10px;  
            }

            figure{
                border: dotted black 2px;
                width:320px;
                margin:auto;
                padding:0;
                margin-top:20px;
            }

            figure img{   
                display:block;
                width:100%;
                width:320px; height:240px;
                margin-left: auto; margin-right:auto;
                opacity:0;
            }

            div#buttons{
                display:flex;
                flex-wrap:nowrap;
                justify-content:space-evenly;
            }
            
            #nav-toggle{
                cursor:pointer;
                display:block;
                width:125px; height:20px;
                background-color:#eee;
                opacity:0.8;
                padding:5px;
                border-radius: 10px;
                margin-top:9px;
                margin-left:10px;
            }
          
            #nav-toggle-cb{
                display:none;
                outline:0;
                opacity:0;
                width:0; height:0
            }
          
            #nav-toggle-cb:checked+#menu{
                display:flex;
            }
          
            .input-group{
                display:flex;
                flex-wrap:nowrap;
                line-height:22px;
                margin:5px 0;
            }
          
            .input-group>label{
                flex:1;
                
            }
          
          select{
                border:1px solid #363636;
                font-size:14px;
                flex:1;
                 height:22px;
                outline:0;
                border-radius:5px;
            }
          
          .switch{
              flex:1;
                display:block;
                position:relative;
            left:-10px;
                line-height:22px;
                font-size:16px;
                height:22px;
            }
            .switch input{
                /* border:10px solid; */
                outline:0;
                opacity:0;
                width:0;
                height:0;
            }
            .slider{
                width:50px;
                height:22px;
                border-radius:22px;
                cursor:pointer;
                background-color:grey;
            }
            .slider,.slider:before{
                display:inline-block;
                transition:.4s;
            }
            .slider:before{
                position:relative;
                content:"";
                border-radius:50%;
                height:16px;
                width:16px;
                left:4px;
                top:3px;
                background-color:#fff;
            }
            input:checked+.slider{
                background-color:#ff3034;
            }
            input:checked+.slider:before{
                -webkit-transform:translateX(26px);
                transform:translateX(26px);
            }
            
            input[type=range]{
                -webkit-appearance:none;
                flex:1;  
                height:22px;
                background:#363636;
                cursor:pointer;
                margin:0;
            }
            input[type=range]:focus{
                outline:0;
            }
            input[type=range]::-webkit-slider-runnable-track{
                width:100%;
                height:2px;
                cursor:pointer;
                background:#EFEFEF;
                border-radius:0;
                border:0 solid #EFEFEF;
            }
            input[type=range]::-webkit-slider-thumb{
                border:1px solid rgba(0,0,30,0);
                height:22px;width:22px;
                border-radius:50px;
                background:#ff3034;
                cursor:pointer;
                -webkit-appearance:none;
                margin-top:-10px;
            }
            input[type=range]:focus::-webkit-slider-runnable-track{
                background:#EFEFEF;
            }

          button{
                display:block;
                margin:5px;
                padding:0 12px;
                border:0;
                line-height:28px;
                cursor:pointer;
                color:#fff;
                background:#ff3034;
                border-radius:5px;
                font-size:16px;
                outline:0;
            }
            button:hover{
                background:#ff494d;
            }
            button:active{
                background:#f21c21;
            }

            .control-group{
                display:block;
                margin:auto;
                z-index:10;
                position :relative;
                background: #f8f403;
                border: black solid 2px;
                top:20px;                   
                width:320px; height:250px;
            }

            /* vertical */
            .vertical{  
                transform: rotate(-90deg);
                left:-70px;
            }
            .horizontal{
                right:20px;
            }
            .control-group input{
                -webkit-appearance:none;
                position:absolute;
                display:inline-block;
                width: 200px;
                height:20px;
                top:45%;
                background:#363636;
                border:5px solid;
                cursor:pointer;
            }
        </style>
    </head>

    <body>
        <section class="main">
            <div id="logo">
                <label for="nav-toggle-cb" id="nav-toggle">&#9776;&nbsp;&nbsp;Toggle Settings</label>
            </div>

            <div id="sidebar">
                <input type="checkbox" id="nav-toggle-cb" >
                <nav id="menu">
                    <div class="input-group" id="framesize-group">
                        <label for="framesize">Resolution</label>
                        <select id="framesize" class="default-action">
                            <option value="6">VGA(640x480)</option>
                            <option value="5">CIF(400x296)</option>
                            <option value="4" selected="selected">QVGA(320x240)</option>
                            <option value="3">HQVGA(240x176)</option>
                            <option value="0">QQVGA(160x120)</option>
                        </select>
                    </div>

                    <div class="input-group" >
                        <label for="flash">Flash</label>
                        <div class="switch">
                            <input id="flash" type="checkbox">
                            <label class="slider" for="flash"></label>
                        </div>
                    </div>

                    <div class="input-group" id="quality-group">
                        <label>Brightness</label>
                        <input type="range" id="flash_bright" min="0" max="255" value="128">
                    </div>

                    <div id="buttons">
                        <button id="get-still">Get Still </button>
                        <button id="toggle-stream">Start Stream @port 9601</button>        
                    </div>  
                </nav>
            </div>

            <figure>
                    <img id="image" src="">
            </figure>

            <div class="control-group" >
                <input type="range" min="-5" max="5" step="1" value="0" class=vertical id="move">
                <input type="range" min="-5" max="5" step="1" value="0"class=horizontal id="turn">
            </div>

        </section>

<!-- javascript start here -->

        <script>
            var URL=document.location.origin;
            function request(obj){
                    let val;                        
                    switch(obj.type){
                        case'checkbox':val=obj.checked? 1:0; break;
                        case'range':
                        case'select-one':val=obj.value; break;
                        case'button':
                        case'submit':val='1'; break;
                        default:
                        return;
                    }
                    console.log(`obj: ${obj}`);
                    console.log(`type: ${obj.type}`);
                    const req=`${URL}/control?var=${obj.id}&val=${val}`;
                    console.log(`log ${req}`)
                    fetch(req).then(rsp=>{console.log(`request to ${req} finished, status: ${rsp.status}`)})
            }


            document.addEventListener('DOMContentLoaded',function(){               

                /*slider*/
                var slider1 = document.getElementById("move");
                var slider2 = document.getElementById("turn");                   

                slider1.oninput = function() {
                    request(slider1);
                }
                slider1.onmouseup= ()=>{
                    slider1.value=0;
                    request(slider1);
                }

                slider2.oninput = function() {      
                    request(slider2);
                }
                slider2.onmouseup= ()=>{
                    slider2.value=0;           
                    request(slider2);
                }

                var led_slider = document.getElementById("flash_bright");
                led_slider.oninput = function(){
                    request(led_slider);
                }

                /*smart phone touch event*/
                slider1.addEventListener('touchend', touch_fun);
                function touch_fun(event){
                    console.log(event.touches,event.type);
                    slider1.value=0;
                    request(slider1);
                }

                slider2.addEventListener('touchend', touch_fun2);
                function touch_fun2(event){
                    console.log(event.touches,event.type);                     
                    slider2.value=0;
                    request(slider2);
                }

                /*switch*/
                const sw = document.getElementById('flash');
                sw.onchange = function(){
                    request(sw);
                }

                const A=document.getElementById('framesize');
                A.onchange=()=>{
                    request(A);
                };   

                /*keyboard*/
                var isSlider1=false, isSlider2=false;
                slider1.onkeydown=event=>event.preventDefault();//cancel default keydown action
                slider2.onkeydown=event=>event.preventDefault();

                document.onkeydown=(event)=>{
                     console.log(event.code);
                    if(event.which==37 && !isSlider2){//left
                        isSlider2=!isSlider2;
                        slider2.value=-5;                            
                        request(slider2);
                    }
                    else if(event.which==39 && !isSlider2){//right
                        isSlider2=!isSlider2;
                        slider2.value=5;
                        request(slider2);
                    }
                    else if(event.which==38 && !isSlider1){//up
                        isSlider1=!isSlider1;
                        slider1.value=5;
                        request(slider1);
                    }
                    else if(event.which==40 && !isSlider1){//down
                        isSlider1=!isSlider1;
                        slider1.value=-5;
                        request(slider1);
                    }
                }
                document.onkeyup=(event)=>{
                    console.log(event.code);
                    if(event.which==37 || event.which==39){
                        isSlider2=false;
                        slider2.value=0;
                        request(slider2);
                    }
                    else if(event.which==38 || event.which==40){
                        isSlider1=false;
                        slider1.value=0;
                        request(slider1);
                    }
                }



                const disable=B=>{B.classList.add('disabled');B.disabled=!0};
                const enable=B=>{B.classList.remove('disabled');B.disabled=!1};

                const img=document.getElementById('image'); 
                const stream_container=document.getElementById('stream-container');
                const get_img=document.getElementById('get-still');
                const toggle_stream=document.getElementById('toggle-stream');


                const streamStop=()=>{
                    window.stop();
                    img.src="";

                    img.style.opacity=0;
                    toggle_stream.innerHTML='Start Stream';
                };
                const streamStart=()=>{
                    img.style.opacity=1;
                    img.src=`${URL}:9601/stream`;
                    toggle_stream.innerHTML='Stop Stream';
                };

                get_img.onclick=()=>{
                    streamStop();
                    img.style.opacity=1;
                    img.src=`${URL}/capture?_cb=${Date.now()}`;  
                };

                toggle_stream.onclick=()=>{
                    'Stop Stream'===toggle_stream.innerHTML?streamStop():streamStart();
                };
            });
        </script>
    </body>
</html>


)rawliteral"; 
