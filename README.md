# RebusLabs_3_Missing_Numbers

21/11/2018

***0*** *Genel
1.  eski linked-list calisma kodumuzu bul. oku ve tekrar yaz.
2.  bir diziyi tekrar eden sayilariyla birlikte linked-list'e tasima calismasi yap. (***1***'de aciklandi.)
3.  calisirsa sorudaki brr ve arr dizileri üzerinde implimente et.
4.  ilerleyebildiğin kadar ilerle, en son sorudaki kaynak kodu analiz et. Tasimayi gerceklestir.
5.  kontrol kodlarını yedekle ve temizle.

***1*** *Dizi analizi
1.  brr dizisinin sifir indisli elemani ile bir linked-list olustur.
2.  bir for icinde dizi elemanlarini gez. (1 indisli elemandan basla, ileri dogru)
3.  her elemanda o elemana kadar olan elemanları yeni bir for dongusu icinde gez. (0 indisten basla, ileri dogru)
4.  value kontrol yap.
5.  daha once rastlanmamis ise linked-list'e bagla!(counter'ı 1!)
6.  raslanmis ise o value'yu iceren nesnenin counter'ını bir artır!
7.  her zaman ilk gordugu elemandan oturu 1 artiracak. ancak bu bir problem degil.
8.  arr dizisi icin de ayni seyi yap.
9.  kontrol kodu yaz: brr ve arr'yi dolasip, value ve counter'ları yazdır.

***2*** *Linked-List Karsilastirmasi
1.  brr linked-list'inden ilk nesne'nin value'sunu yine bir for dongusu icinde al.
2.  yine onunda icinde olan bir for ile arr linked list'ini dolasarak value control yap.
3.  value kontrol bos dondu ise final dizinin 0 indisli ogesine value'yu yazdır.(ve final_counter +1 (indis sayıcı))
4.  ve bir sonraki brr nesnesi'nin kontrolune gec (kapsayıcı for dongusune yani)
5.  value kontrol eslesti ise (ki eslesirse yalniz bir eslesme olur), counter kontrolune gec.
6.  counter kontrolu eslesti ise, hicbir sey yapma. kapsayıcı for'a gec, yani bir sonraki brr'nesnesine.
7.  eslesme yok ise (brr counter'ı %100 daha buyuk olmak zorunda) fark kac olursa olsun, value'yu al ve final diziye yazdır.
8.  final_counter'ı bir artır.
9.  kontrol kodu yaz: final_dizi'yi yazdır.

***3*** *Final dizi
1. final_dizi'yi buble sort'la ve yazdır. (final dizinin boyutu = m-n olmalı, yani m-n ögeye sahip olmalı!)

