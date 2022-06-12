package main

import (
	"encoding/csv"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
)

type a_1031 struct {
	End_time_stamp_1031 int64
	Value_1031          string
}

type Recieve_network_container struct {
	//Result []SimpleMetric
	Result []SimpleMetric `json:"Result"`
}

type SimpleMetric struct {
	Metric     MetricInfo       `json:"metric"`
	Detaildata []DetaildataInfo `json:"detaildata"`
}

type MetricInfo struct {
	MetricName                string `json:"__name__"`
	Beta_kubernetes_io_arch   string `json:"beta_kubernetes_io_arch"`
	Beta_kubernetes_io_os     string `json:"beta_kubernetes_io_os"`
	Container                 string `json:"container"`
	Hardware_type             string `json:"hardware_type"`
	ID                        string `json:"id"`
	Image                     string `json:"image"`
	Instance                  string `json:"instance"`
	Interface                 string `json:"interface"`
	Job                       string `json:"job"`
	Kubernetes_io_arch        string `json:"kubernetes_io_arch"`
	Kubernetes_io_hostname    string `json:"kubernetes_io_hostname"`
	Kubernetes_io_os          string `json:"kubernetes_io_os"`
	Name                      string `json:"name"`
	Namespace                 string `json:"namespace"`
	Octopus_openi_pcl_cn_node string `json:"octopus_openi_pcl_cn_node"`
	Pod                       string `json:"pod"`
	ResourceType              string `json:"resourceType"`
}

type DetaildataInfo struct {
	StartTimeStamp int64    `json:"start_time_stamp"`
	Len            int64    `json:"length"`
	EndTimeStamp   int64    `json:"End_time_stamp"`
	Values         []string `json:"values"`
}

func ReadFile_kube_pod_created(file_kube_pod_created string) string {
	//f, err := os.Open("./kube_pod_created_2021-06-15.log")
	//f, err := os.Open("./kube_pod_created_2021-06-15-fthtest.log")
	//f, err := os.Open("./kube_pod_created_2021-06-15.log")
	f, err := os.Open(file_kube_pod_created)
	if err != nil {
		fmt.Println("read file fail", err)
		return ""
	}
	defer f.Close()
	//debug
	//fmt.Println(file_kube_pod_created)

	fd, err := ioutil.ReadAll(f)
	if err != nil {
		fmt.Println("read to fd fail", err)
		return ""
	}

	return string(fd)
}

// Strval 获取变量的字符串值
// 浮点型 3.0将会转换成字符串3, "3"
// 非数值或字符类型的变量将会被转换成JSON格式字符串
func Strval(value interface{}) string {
	// interface 转 string
	var key string
	if value == nil {
		return key
	}

	switch value.(type) {
	case float64:
		ft := value.(float64)
		key = strconv.FormatFloat(ft, 'f', -1, 64)
	case float32:
		ft := value.(float32)
		key = strconv.FormatFloat(float64(ft), 'f', -1, 64)
	case int:
		it := value.(int)
		key = strconv.Itoa(it)
	case uint:
		it := value.(uint)
		key = strconv.Itoa(int(it))
	case int8:
		it := value.(int8)
		key = strconv.Itoa(int(it))
	case uint8:
		it := value.(uint8)
		key = strconv.Itoa(int(it))
	case int16:
		it := value.(int16)
		key = strconv.Itoa(int(it))
	case uint16:
		it := value.(uint16)
		key = strconv.Itoa(int(it))
	case int32:
		it := value.(int32)
		key = strconv.Itoa(int(it))
	case uint32:
		it := value.(uint32)
		key = strconv.Itoa(int(it))
	case int64:
		it := value.(int64)
		key = strconv.FormatInt(it, 10)
	case uint64:
		it := value.(uint64)
		key = strconv.FormatUint(it, 10)
	case string:
		key = value.(string)
	case []byte:
		key = string(value.([]byte))
	default:
		newValue, _ := json.Marshal(value)
		key = string(newValue)
	}

	return key
}

func recieve_network_container04() {
	//创建一次map  （代码不用变） 二层map，  String[String[String]]

	var map_recieve_network_container map[string]map[string]string
	map_recieve_network_container = make(map[string]map[string]string)

	var str []byte
	//读文件，存到map中， 需要重复读，一口气存下所有文件的created

	var fd string
	var file_recieve_network_container string
	myfolder1 := `E:\B\trace0927\created_pod\recieve_network_container_20-11-19_21-10-10\`

	files1, _ := ioutil.ReadDir(myfolder1)
	//debug
	fmt.Println("files1=", files1)
	var recieve_network_container Recieve_network_container

	for _, file1 := range files1 {
		//file_recieve_network_container = `E:\B\trace0927\created_pod\recieve_network_container_20-11-19_21-10-10\2020-11-19\` + file1.Name()
		myfolder2 := myfolder1 + file1.Name()
		fmt.Println(myfolder2)
		files2, _ := ioutil.ReadDir(myfolder2)
		for _, file2 := range files2 {

			file_recieve_network_container = myfolder2 + "\\" + file2.Name()
			//debug
			fmt.Println("file_recieve_network_container=", file_recieve_network_container)
			fd = ReadFile_kube_pod_created(file_recieve_network_container)

			//str = append([]byte(fd)) 三个点是精华， ...
			//str = append(str, []byte(fd)...)  两个必须要加...

			fd = "{\"Result\":" + fd + "}"
			str = append([]byte(fd))
			json.Unmarshal(str, &recieve_network_container)

			var strTemp1 string
			var strTemp2 string
			var intTemp1 int64
			var intTemp2 int64
			//var err error
			for i := 0; i < len(recieve_network_container.Result); i++ {

				if _, ok := map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod]; !ok {
					map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod] = make(map[string]string)
				}

				strTemp1 = map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod][recieve_network_container.Result[i].Metric.Interface]
				strTemp2 = recieve_network_container.Result[i].Detaildata[len(recieve_network_container.Result[i].Detaildata)-1].Values[len(recieve_network_container.Result[i].Detaildata[len(recieve_network_container.Result[i].Detaildata)-1].Values)-1]
				intTemp1, _ = strconv.ParseInt(strTemp1, 10, 64)
				intTemp2, _ = strconv.ParseInt(strTemp2, 10, 64)

				if intTemp1 <= intTemp2 {
					map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod][recieve_network_container.Result[i].Metric.Interface] = recieve_network_container.Result[i].Detaildata[len(recieve_network_container.Result[i].Detaildata)-1].Values[len(recieve_network_container.Result[i].Detaildata[len(recieve_network_container.Result[i].Detaildata)-1].Values)-1]
				}
			}

		}
	}

	//创建csv，把map转换成[]string,存到csv中 （存好map之后，下面的代码不用变化）
	file_csv, err := os.Create("recieve_network_container.csv") //创建文件
	if err != nil {
		panic(err)
	}
	defer file_csv.Close()

	file_csv.WriteString("\xEF\xBB\xBF") //写入UTF-8 BOM

	writer_csv := csv.NewWriter(file_csv) //创建一个新的写入文件流

	for key_map, value_map := range map_recieve_network_container {
		//debug
		//fmt.Println(key_map, value_map)
		data_string := []string{key_map, Strval(value_map)}
		writer_csv.Write(data_string) //写入数据
		writer_csv.Flush()
	}

}

func send_network_container05() {
	//创建一次map  （代码不用变） 二层map，  String[String[String]]

	var map_recieve_network_container map[string]map[string]string
	map_recieve_network_container = make(map[string]map[string]string)

	var str []byte
	//读文件，存到map中， 需要重复读，一口气存下所有文件的created

	var fd string
	var file_recieve_network_container string
	myfolder1 := `E:\B\trace0927\created_pod\send_network_container_20-11-19_21-10-10\`

	files1, _ := ioutil.ReadDir(myfolder1)
	//debug
	fmt.Println("files1=", files1)
	var recieve_network_container Recieve_network_container

	for _, file1 := range files1 {
		//file_recieve_network_container = `E:\B\trace0927\created_pod\recieve_network_container_20-11-19_21-10-10\2020-11-19\` + file1.Name()
		myfolder2 := myfolder1 + file1.Name()
		fmt.Println(myfolder2)
		files2, _ := ioutil.ReadDir(myfolder2)
		for _, file2 := range files2 {

			file_recieve_network_container = myfolder2 + "\\" + file2.Name()
			//debug
			fmt.Println("file_recieve_network_container=", file_recieve_network_container)
			fd = ReadFile_kube_pod_created(file_recieve_network_container)

			//str = append([]byte(fd)) 三个点是精华， ...
			//str = append(str, []byte(fd)...)  两个必须要加...

			fd = "{\"Result\":" + fd + "}"
			str = append([]byte(fd))
			json.Unmarshal(str, &recieve_network_container)

			var strTemp1 string
			var strTemp2 string
			var intTemp1 int64
			var intTemp2 int64
			//var err error
			for i := 0; i < len(recieve_network_container.Result); i++ {

				if _, ok := map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod]; !ok {
					map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod] = make(map[string]string)
				}

				strTemp1 = map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod][recieve_network_container.Result[i].Metric.Interface]
				strTemp2 = recieve_network_container.Result[i].Detaildata[len(recieve_network_container.Result[i].Detaildata)-1].Values[len(recieve_network_container.Result[i].Detaildata[len(recieve_network_container.Result[i].Detaildata)-1].Values)-1]
				intTemp1, _ = strconv.ParseInt(strTemp1, 10, 64)
				intTemp2, _ = strconv.ParseInt(strTemp2, 10, 64)

				if intTemp1 <= intTemp2 {
					map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod][recieve_network_container.Result[i].Metric.Interface] = recieve_network_container.Result[i].Detaildata[len(recieve_network_container.Result[i].Detaildata)-1].Values[len(recieve_network_container.Result[i].Detaildata[len(recieve_network_container.Result[i].Detaildata)-1].Values)-1]
				}
			}

		}
	}

	//创建csv，把map转换成[]string,存到csv中 （存好map之后，下面的代码不用变化）
	file_csv, err := os.Create("send_network_container.csv") //创建文件
	if err != nil {
		panic(err)
	}
	defer file_csv.Close()

	file_csv.WriteString("\xEF\xBB\xBF") //写入UTF-8 BOM

	writer_csv := csv.NewWriter(file_csv) //创建一个新的写入文件流

	for key_map, value_map := range map_recieve_network_container {
		//debug
		//fmt.Println(key_map, value_map)
		data_string := []string{key_map, Strval(value_map)}
		writer_csv.Write(data_string) //写入数据
		writer_csv.Flush()
	}

}

func simple_container_cpu_usage_seconds_total06() {
	//创建一次map  （代码不用变） 二层map，  String[String[String]]

	var map_recieve_network_container map[string]map[string]string
	map_recieve_network_container = make(map[string]map[string]string)

	var str []byte
	//读文件，存到map中， 需要重复读，一口气存下所有文件的created

	var fd string
	var file_recieve_network_container string
	myfolder1 := `E:\B\trace0927\created_pod\usage_pod_container_20-11-19_21-10-10\`

	files1, _ := ioutil.ReadDir(myfolder1)
	//debug
	fmt.Println("files1=", files1)
	var recieve_network_container Recieve_network_container

	for _, file1 := range files1 {
		//file_recieve_network_container = `E:\B\trace0927\created_pod\recieve_network_container_20-11-19_21-10-10\2020-11-19\` + file1.Name()
		myfolder2 := myfolder1 + file1.Name()
		fmt.Println(myfolder2)
		files2, _ := ioutil.ReadDir(myfolder2)
		for _, file2 := range files2 {

			file_recieve_network_container = myfolder2 + "\\" + file2.Name()
			//debug
			fmt.Println("file_recieve_network_container=", file_recieve_network_container)
			fd = ReadFile_kube_pod_created(file_recieve_network_container)

			//str = append([]byte(fd)) 三个点是精华， ...
			//str = append(str, []byte(fd)...)  两个必须要加...

			fd = "{\"Result\":" + fd + "}"
			str = append([]byte(fd))
			json.Unmarshal(str, &recieve_network_container)

			var strTemp1 string
			var strTemp2 string
			var intTemp1 int64
			var intTemp2 int64
			//var err error
			for i := 0; i < len(recieve_network_container.Result); i++ {

				if _, ok := map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod]; !ok {
					map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod] = make(map[string]string)
				}

				strTemp1 = map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod][recieve_network_container.Result[i].Metric.Interface]
				strTemp2 = recieve_network_container.Result[i].Detaildata[len(recieve_network_container.Result[i].Detaildata)-1].Values[len(recieve_network_container.Result[i].Detaildata[len(recieve_network_container.Result[i].Detaildata)-1].Values)-1]
				intTemp1, _ = strconv.ParseInt(strTemp1, 10, 64)
				intTemp2, _ = strconv.ParseInt(strTemp2, 10, 64)

				if intTemp1 <= intTemp2 {
					map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod][recieve_network_container.Result[i].Metric.Interface] = recieve_network_container.Result[i].Detaildata[len(recieve_network_container.Result[i].Detaildata)-1].Values[len(recieve_network_container.Result[i].Detaildata[len(recieve_network_container.Result[i].Detaildata)-1].Values)-1]
				}
			}

		}
	}

	//创建csv，把map转换成[]string,存到csv中 （存好map之后，下面的代码不用变化）
	file_csv, err := os.Create("simple_container_cpu_usage_seconds_total.csv") //创建文件
	if err != nil {
		panic(err)
	}
	defer file_csv.Close()

	file_csv.WriteString("\xEF\xBB\xBF") //写入UTF-8 BOM

	writer_csv := csv.NewWriter(file_csv) //创建一个新的写入文件流

	for key_map, value_map := range map_recieve_network_container {
		//debug
		//fmt.Println(key_map, value_map)
		data_string := []string{key_map, Strval(value_map)}
		writer_csv.Write(data_string) //写入数据
		writer_csv.Flush()
	}

}

func EndTimeStamp_cpu_usage_seconds_total07() {
	//创建一次map  （代码不用变） 二层map，  String[String[String]]

	// var map_recieve_network_container map[string]map[string]string
	// map_recieve_network_container = make(map[string]map[string]string)

	// var map_recieve_network_container map[string][]string
	// map_recieve_network_container = make(map[string][]string)
	var map_recieve_network_container map[string]*a_1031
	map_recieve_network_container = make(map[string]*a_1031)

	var str []byte
	//读文件，存到map中， 需要重复读，一口气存下所有文件的created

	var fd string
	var file_recieve_network_container string
	//myfolder1 := `E:\B\trace0927\created_pod\usage_pod_container_20-11-19_21-10-10\`
	myfolder1 := `/data/usage_pod_container/`

	files1, _ := ioutil.ReadDir(myfolder1)
	//debug
	fmt.Println("files1=", files1)
	var recieve_network_container Recieve_network_container

	for _, file1 := range files1 { //二层循环
		//file_recieve_network_container = `E:\B\trace0927\created_pod\recieve_network_container_20-11-19_21-10-10\2020-11-19\` + file1.Name()
		myfolder2 := myfolder1 + file1.Name()
		fmt.Println(myfolder2)
		files2, _ := ioutil.ReadDir(myfolder2)
		for _, file2 := range files2 { //二层循环

			//file_recieve_network_container = myfolder2 + "\\" + file2.Name()
			file_recieve_network_container = myfolder2 + "/" + file2.Name()
			//debug
			fmt.Println("414file_recieve_network_container=", file_recieve_network_container)
			fmt.Println("415file_EndTimeStamp_cpu_usage_seconds_total07=", file_recieve_network_container)
			fd = ReadFile_kube_pod_created(file_recieve_network_container)

			//str = append([]byte(fd)) 三个点是精华， ...
			//str = append(str, []byte(fd)...)  两个必须要加...
			//转换成标准json格式,一个.log文件一个Result 二层循环
			fd = "{\"Result\":" + fd + "}"
			str = append([]byte(fd))
			json.Unmarshal(str, &recieve_network_container)

			//debug
			//fmt.Println("426file_recieve_network_container=", file_recieve_network_container)
			var strTemp1 string
			var strTemp2 string
			var strTemp3 int64
			var intTemp1 int64
			var intTemp2 int64
			//var err error
			//Result的值 存着 切片 切片的元素是 一个个{"metric": } , {"metric":}}  for循环 每个i处理一个metric
			for i := 0; i < len(recieve_network_container.Result); i++ {

				if _, ok := map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod]; !ok {
					//map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod] = make(map[string]string)
					//给map[pod]分配内存  // 其长度为 3 个元素，容量为 5 个元素 slice := make([]int, 3, 5)
					//map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod] = make([]string, 2, 2)
					map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod] = new(a_1031)
				}

				//strTemp1:获得之前的值 得改成一维的  （interface（CPU usage不需要网卡））  strTemp2:获得value值（参考06函数不用改） strTemp3:获得value对应的End_time_stamp的值
				//strTemp1 = map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod][recieve_network_container.Result[i].Metric.Interface]
				strTemp1 = map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod].Value_1031
				strTemp3 = recieve_network_container.Result[i].Detaildata[len(recieve_network_container.Result[i].Detaildata)-1].EndTimeStamp
				strTemp2 = recieve_network_container.Result[i].Detaildata[len(recieve_network_container.Result[i].Detaildata)-1].Values[len(recieve_network_container.Result[i].Detaildata[len(recieve_network_container.Result[i].Detaildata)-1].Values)-1]
				intTemp1, _ = strconv.ParseInt(strTemp1, 10, 64)
				intTemp2, _ = strconv.ParseInt(strTemp2, 10, 64)

				if intTemp1 <= intTemp2 {
					//两层map map[string]map[string]string   外层按pod的值 存，内层map[][] interface  然后里面是 value
					//改 不需要interface这一层
					//map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod][recieve_network_container.Result[i].Metric.Interface] = recieve_network_container.Result[i].Detaildata[len(recieve_network_container.Result[i].Detaildata)-1].Values[len(recieve_network_container.Result[i].Detaildata[len(recieve_network_container.Result[i].Detaildata)-1].Values)-1]
					//map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod]= recieve_network_container.Result[i].Detaildata[len(recieve_network_container.Result[i].Detaildata)-1].Values[len(recieve_network_container.Result[i].Detaildata[len(recieve_network_container.Result[i].Detaildata)-1].Values)-1]
					map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod].Value_1031 = strTemp2
					map_recieve_network_container[recieve_network_container.Result[i].Metric.Pod].End_time_stamp_1031 = strTemp3

				}
			}

		}
	}

	//创建csv，把map转换成[]string,存到csv中 （存好map之后，下面的代码不用变化）
	file_csv, err := os.Create("EndTimeStamp_cpu_usage_seconds_total.csv") //创建文件
	if err != nil {
		panic(err)
	}
	defer file_csv.Close()

	file_csv.WriteString("\xEF\xBB\xBF") //写入UTF-8 BOM

	writer_csv := csv.NewWriter(file_csv) //创建一个新的写入文件流

	title_string := []string{"pod,	End_time_stamp,	value"}
	writer_csv.Write(title_string)
	for key_map, value_map := range map_recieve_network_container {
		//debug
		//fmt.Println(key_map, value_map)
		//data_string := []string{key_map, Strval(value_map)}
		data_string := []string{key_map, Strval(value_map.End_time_stamp_1031), Strval(value_map.Value_1031)}
		writer_csv.Write(data_string) //写入数据
		writer_csv.Flush()
	}

}

func main() {
	//fmt.Println("hello")

	//recieve_network_container04()
	//send_network_container05()
	//simple_container_cpu_usage_seconds_total06()
	EndTimeStamp_cpu_usage_seconds_total07()
}
