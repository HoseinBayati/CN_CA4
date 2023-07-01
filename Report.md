---
lang: ar
dir: rtl
title: "Put the title"
author: "Author name"
date: "Publication date"
---

<body dir="rtl" style="text-align: right">
<font size="3">

# <center style="color: yellow"> **شبکه‌های کامپیوتری** </center><br/>

## <center style="color: yellow"> **تمرین برنامه نویسی شماره ۰4** </center><br/>

## <center> محمد جلالی : ۸۱۰۱۹۸۵۰۲  &nbsp;&nbsp;   &nbsp;&nbsp;   حسین بیاتی : ۸۱۰۱۹۸۳۶۶ </center>
## <center> </center><br/>

<hr style="border-bottom: solid 1px yellow"><br/>

### <center><strong style="color: orange; font-size: 28px;"> پیاده سازی و تحلیل الگوریتمهای کنترل ازدحام </strong><br/><span style="color: orange; font-size: 24px;">(Border Gateway - Distance Vector - Link State) </span></center><br/>

<ul style="list-style-type: none">
    <li>
        <h2>
            <strong style="color: yellow">
                نحوه اجرا            
            </strong>
        </h2>
            <br/>
            <h3>
                <ul>
                    <li>
                        با وارد کردن دستور <strong style="color: beige">make</strong> در پوشه <strong style="color: beige">Code</strong> پروژه، فایل اجرایی در این پوشه ساخته می‌شود
                        <br/><br/>
                        <image src="./images/make.png" style="width: 100%"/>
                    </li><br/>
                    <li>
                        با وارد کردن دستور <strong style="color: beige"> tcpSim.out/. </strong> برنامه راه اندازی شده و سیمولیشن انجام میپذیرد.
                        <br/><br/>
                        <image src="./images/run.png" style="width: 100%"/>
                    </li>
                </ul><br/>
                برنامه به شکل پویا پیاده ساخته شده و محدودیتی برای شمار پیوندها نیست.
            </h3>
            <br/><hr style="border-bottom: solid 1px yellow"><br/>
    </li>
    <li>
        <h2>
            <strong style="color: yellow">
                ساختار
            </strong>
        </h2>
            <br/>
            <h3>
                برنامه شامل سه کلاس می‌باشد که هریک برای پیاده سازی یکی از پرتکل های گفته شده در پروژه هست که در آن کلاس فواعد آن هر پرتکل پیاده سازی شده.:
                <br/><br/>
                <ul>
                    <li>
                        <strong style="color: beige">RenoTCPConnection:</strong> &nbsp; این کلاس همان طور که از اسم آن قابل حدس است برای شبیه سازی پرتکل <strong style="color: beige">Reno TCP</strong> به کار گرفته شده است در تابع <strong style="color: beige">main</strong> برنامه از آن نمونه گرفته شده و شبیه سازی آن انجام شده.
                    </li><br/>
                    <li>
                        <strong style="color: beige">NewRenoTCPConnection:</strong> &nbsp; این کلاس همانند کلاس قبل برای شبیه سازی قواعد مربوط به <strong style="color: beige">New Reno</strong> به کار گرفته شده است و همانند سایر کلاس ها در تابع <strong style="color: beige">main:</strong> نمونه ای از آن ساخته شده است و کارهای شبیه سازی انجام داده شده 
                    </li><br/>
                    <li>
                        <strong style="color: beige">BBRTCPConnection:</strong> &nbsp; همانند کلاس های قبلی برای شبیه سازی پرتکل ساخته شده ولی پرتکلش تفاوت بیشتری با قبلی ها دارد و توسط شرکت گوگل ایجاد شده و افزایش امکانات سخت افزاری کمک شایانی به بهبود عملکرد این پروتکل دارد.
                    </li><br/>
                </ul>
                در فایل  <strong style="color: beige">main.cpp</strong> نیز 5 تابع دارد که برای ایجاد و شبیه سازی به وسیله کلاس های ایجاد شده است.
                <br/><br/>
                <ul>
                    <li>
                        <strong style="color: beige">calculatePacketLossProbability:</strong> &nbsp; این تابع برای شبیه سازی احتمال از دست رفتن  پنجره بسته استفاده میشود که برای هر پکت یک درصد احتمال از دست رفتن هر بسته در نظز گرفته شده و از آنجا که بسته ها هم سایز فرض شده اشکالی ایجاد نمیکند و بداهتا اگر پنچره بزرگ تر بود این احتمال نیز باید افزایش پیدا کند که به صورت خطی انچام پذیرفته است .
                    </li><br/>
                    <li>
                        <strong style="color: beige">test funcs:</strong> &nbsp; این توابع به منظور کنترل عملکرد شبیه سازی استفاده میشود و با صدا کرد این تابع برای پرتکل مد نظر پنچره آن را ارسال میکند در صورت رخ داد گم شده تابع مربوطه از کلاس مد نظر صدا خواهد شد و اینگونه قواعد پرتکل برای گمشدن بسته ها ارسال موفقیت آمیز آنها اعمال خواهد شد
                    </li><br/>
                    <li>
                        <strong style="color: beige">main:</strong> &nbsp; در این تابع نمونه ای از هر کلاس ایجاد شده و سپس ده مرتبه در حلقه طی خواهیم کرد در هربار عبور از حلقه ما تابع ارسال و کنترل پرتکل مربوط را صدا میکنیم و بدین نحو پرتکل ها را تست میکنیم..
                    </li><br/>
                </ul>
            </h3>
            <hr style="border-bottom: solid 1px yellow"><br/>
    </li>
    <li>
        <h2>
            <strong style="color: yellow">
                شرح کد و عملکرد آن
            </strong>
        </h2>
            <br/>
            <h3>
                <ul>
                     <li>
                        <strong style="color: beige">کلاس BBRTCPConnection: &nbsp;</strong><br/><br/>
                        <ul>
                            <li>
                                <strong style="color: #80ced6">
                                    public
                                </strong> 
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                             RenoTCPConnection(int init_cwnd, int init_ssthresh) <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                            void sendData() <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                            void onPacketLoss() <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                           void onRTTUpdate(int new_rtt) <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                           int getCwnd() <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                           int getSsthresh() <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                           int getRtt() <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                            </li><br/>
                        </ul>
                    </li><br/>
                     <li>
                        <strong style="color: beige">کلاس RenoTCPConnection: &nbsp;</strong><br/><br/>
                        <ul>
                            <li>
                                <strong style="color: #80ced6">
                                    public
                                </strong> 
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                             RenoTCPConnection(int init_cwnd, int init_ssthresh) <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                            void sendData() <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                            void onPacketLoss() <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                           void onRTTUpdate(int new_rtt) <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                           int getCwnd() <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                           int getSsthresh() <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                           int getRtt() <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                            </li><br/>
                        </ul>
                    </li><br/>
                    <li>
                        <strong style="color: beige">کلاس NewRenoTCPConnection: &nbsp;</strong><br/><br/>
                        <ul>
                            <li>
                                <strong style="color: #80ced6">
                                    public
                                </strong> 
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                             RenoTCPConnection(int init_cwnd, int init_ssthresh) <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                            void sendData() <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                            void onPacketLoss() <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                           void onRTTUpdate(int new_rtt) <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                           int getCwnd() <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                           int getSsthresh() <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                           int getRtt() <span style="color: beige">  </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                            </li><br/>
                        </ul>
                    </li><br/>
                        </ul>
                    </li><br/>
                </ul>
            </h3>
            <hr style="border-bottom: solid 1px yellow"><br/>
    </li>
     <li>
        <h2>
            <strong style="color: yellow">
                تحلیل نتایج
            </strong>
        </h2>
            <br/>
            <h3>
                 نتایج سه شبیه سازی به ما نشان میدهد که تغییرات روی <strong style="color: beige">reno tcp</strong>  موثر بوده و باعث بهبهود آن شده و در واقع پرتکل <strong style="color: beige"> new reno tcp</strong> با استفاده از <strong style="color: beige">selection recovery</strong> عملکرد بهتری دارد با <strong style="color: beige">BBR</strong> باید گفته عملکرد آن وابستگی زیادی به امکانات خط دارد در صورتی که امکانات ما مناسب و قوی باشد این پرتکل از تمام این قدرت تلاش میکند استفاده کند واین تلاش منجر به عملکرد بهتر آن نسبت به سایرین میشود. 
            </h3>
    </li>
</ul>