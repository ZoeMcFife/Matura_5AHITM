import './Calculator.css'
import Result from "../Result/Result.jsx";
import Button from "../Button/Button.jsx";

function Calculator() {

    return (
        <div className={"calculator-container"}>
            <Result></Result>
            <div className="calculator">
                <Button visualValue={7} functionalValue={7}></Button>
                <Button visualValue={8} functionalValue={8}></Button>
                <Button visualValue={9} functionalValue={9}></Button>
                <Button visualValue={'/'} functionalValue={'/'}></Button>
                <Button visualValue={'Back'} functionalValue={'Back'}></Button>
                <Button visualValue={'C'} functionalValue={'Clear'}></Button>

                <Button visualValue={4} functionalValue={4}></Button>
                <Button visualValue={5} functionalValue={5}></Button>
                <Button visualValue={6} functionalValue={6}></Button>
                <Button visualValue={'*'} functionalValue={'*'}></Button>
                <Button visualValue={'('} functionalValue={'('}></Button>
                <Button visualValue={')'} functionalValue={')'}></Button>

                <Button visualValue={1} functionalValue={1}></Button>
                <Button visualValue={2} functionalValue={2}></Button>
                <Button visualValue={3} functionalValue={3}></Button>
                <Button visualValue={'-'} functionalValue={'-'}></Button>
                <Button visualValue={'x²'} functionalValue={'pow'}></Button>
                <Button visualValue={'sqrt(x)'} functionalValue={'sqrt'}></Button>

                <Button visualValue={0} functionalValue={0}></Button>
                <Button visualValue={'%'} functionalValue={'%'}></Button>
                <Button visualValue={'.'} functionalValue={'.'}></Button>
                <Button visualValue={'+'} functionalValue={'+'}></Button>


                <div className={"equals"}>
                    <Button visualValue={'='} functionalValue={'='}></Button>
                </div>
            </div>
        </div>
    )
}

export default Calculator